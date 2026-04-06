#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <algorithm>
#include <memory>

template<typename TKey, typename TCompare = std::less<TKey>, typename TAllocator = std::allocator<TKey>>
class AvlTree {
private:
  struct _Node {
    TKey _key;
    int _height;
    _Node* _left;
    _Node* _right;

    explicit _Node(const TKey& k)
        : _key(k)
        , _height(1)
        , _left(nullptr)
        , _right(nullptr) {
    }
  };
  
public:
  class iterator {
  private:
    _Node* _stack[64];
    int _top;

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = TKey;
    using difference_type = std::ptrdiff_t;
    using pointer = const TKey*;
    using reference = const TKey&;

    iterator()
        : _top(-1) 
    {
    }

    explicit iterator(_Node* root)
        : _top(-1) 
    {
      _most_left(root);
    }

    reference operator*() const {
      return _stack[_top]->_key;
    }

    pointer operator->() const {
      return &_stack[_top]->_key;
    }

    iterator& operator++() {
      _Node* n = _stack[_top--];

      if(n->_right != nullptr) {
        _most_left(n->_right);
      }

      return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(const iterator& other) const {
      if(_top != other._top) {
        return false;
      }

      if(_top == -1) {
        return true;
      }

      return _stack[_top] == other._stack[other._top];
    }

    bool operator!=(const iterator& other) const {
      return ! (*this == other);
    }

  private:
    void _most_left(_Node* n) {
      while(n != nullptr) {
        _stack[++_top] = n;
        n = n->_left;
      }
    }
  };

private:
  using _Allocator = typename std::allocator_traits<TAllocator>::template rebind_alloc<_Node>;

  _Node* root = nullptr;

  bool _cache_inserted = false;
  bool _cache_erased = false;

  TCompare _less;
  _Allocator _allocator;

public:
  AvlTree() = default;

  AvlTree(TCompare comp, TAllocator alloc = TAllocator())
      : _less(comp)
      , _allocator(alloc) {
  }

  ~AvlTree() {
    _destroy(root);
  }

  AvlTree(AvlTree&& other)
      : _less(std::move(other._less))
      , _allocator(std::move(other._allocator))
      , root(other.root) {
    other.root = nullptr;
  }

  AvlTree(const AvlTree& other) = delete;

  AvlTree& operator=(AvlTree&& other) {
    if(this != &other) {
      _destroy(root);

      _less = std::move(other._less);
      _allocator = std::move(other._allocator);

      root = other.root;
      other.root = nullptr;
    }

    return *this;
  }

  AvlTree& operator=(const AvlTree& other) = delete;

public: // api
  iterator begin() const {
    return iterator(root);
  }

  iterator end() const {
    return iterator();
  }

  [[nodiscard]] bool empty() const {
    return root == nullptr;
  }

  bool insert(const TKey& k) {
    _cache_inserted = false;
    root = _insert(root, k);
    return _cache_inserted;
  }

  bool erase(const TKey& k) {
    _cache_erased = false;
    root = _erase(root, k);
    return _cache_erased;
  }

  [[nodiscard]] bool contains(const TKey& k) const {
    return _contains(root, k);
  }

private: // memory management
  void _destroy(_Node* n) {
    if(n != nullptr) {
      _destroy(n->_left);
      _destroy(n->_right);
      _destroy_node(n);
    }
  }

  _Node* _make_node(const TKey& k) {
    _Node* n = _allocator.allocate(1);
    new(n) _Node(k);
    return n;
  }

  void _destroy_node(_Node* n) {
    n->~_Node();
    _allocator.deallocate(n, 1);
  }

private: // avl tree logic
  [[nodiscard]] static int _height(_Node* n) {
    if(n == nullptr) {
      return 0;
    }

    return n->_height;
  }

  static void _update_height(_Node* n) {
    int hl = _height(n->_left);
    int hr = _height(n->_right);
    n->_height = (hl > hr ? hl : hr) + 1;
  }

  [[nodiscard]] static int _balance_factor(_Node* n) {
    return _height(n->_left) - _height(n->_right);
  }

  [[nodiscard]] static _Node* _rotate_right(_Node* y) {
    _Node* x = y->_left;
    _Node* t2 = x->_right;

    x->_right = y;
    y->_left = t2;

    _update_height(y);
    _update_height(x);

    return x;
  }

  [[nodiscard]] static _Node* _rotate_left(_Node* x) {
    _Node* y = x->_right;
    _Node* t2 = y->_left;

    y->_left = x;
    x->_right = t2;

    _update_height(x);
    _update_height(y);

    return y;
  }

  [[nodiscard]] static _Node* _rebalance(_Node* n) {
    _update_height(n);
    int balance_factor = _balance_factor(n);

    if(balance_factor > 1) {
      if(_balance_factor(n->_left) < 0) {
        n->_left = _rotate_left(n->_left);
      }

      return _rotate_right(n);
    }

    if(balance_factor < -1) {
      if(_balance_factor(n->_right) > 0) {
        n->_right = _rotate_right(n->_right);
      }

      return _rotate_left(n);
    }

    return n;
  }

private: // tree operations
  _Node* _insert(_Node* n, const TKey& k) {
    if(n == nullptr) {
      _cache_inserted = true;
      return _make_node(k);
    }

    if(_less(k, n->_key)) {
      n->_left = _insert(n->_left, k);
    } else if(_less(n->_key, k)) {
      n->_right = _insert(n->_right, k);
    } else {
      return n;
    }

    return _rebalance(n);
  }

  [[nodiscard]] static _Node* _most_left(_Node* n) {
    while(n->_left != nullptr) {
      n = n->_left;
    }

    return n;
  }

  _Node* _erase(_Node* n, const TKey& k) {
    if(n == nullptr) {
      return nullptr;
    }

    if(_less(k, n->_key)) {
      n->_left = _erase(n->_left, k);
    } else if(_less(n->_key, k)) {
      n->_right = _erase(n->_right, k);
    } else {
      if(n->_left == nullptr || n->_right == nullptr) {
        _cache_erased = true;
        _Node* child = (n->_left != nullptr) ? n->_left : n->_right;
        _destroy_node(n);
        return child;
      } else {
        _Node* succ = _most_left(n->_right);
        n->_key = succ->_key;
        n->_right = _erase(n->_right, succ->_key);
      }
    }

    return _rebalance(n);
  }

  bool _contains(_Node* n, const TKey& k) const {
    while(n != nullptr) {
      if(_less(k, n->_key)) {
        n = n->_left;
      } else if(_less(n->_key, k)) {
        n = n->_right;
      } else {
        return true;
      }
    }

    return false;
  }
};
