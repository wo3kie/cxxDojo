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

template<typename T>
struct AvlNode final {
  T value{};
  int height{1};

  std::unique_ptr<AvlNode> _left{};
  std::unique_ptr<AvlNode> _right{};

  explicit AvlNode(const T& v)
      : value(v) {
  }

  int left_height() const {
    return _left ? _left->height : 0;
  }

  int right_height() const {
    return _right ? _right->height : 0;
  }

  void update_height() {
    height = 1 + std::max(left_height(), right_height());
  }

  int balance() const {
    return right_height() - left_height();
  }
};

template<typename T>
class AvlTree final {
public:
  void insert(const T& value) {
    _root = insert_impl(std::move(_root), value);
  }

  T* find(const T& value) const {
    AvlNode<T>* node = _root.get();

    while(node) {
      if(value < node->value) {
        node = node->_left.get();
      } else if(value > node->value) {
        node = node->_right.get();
      } else {
        return &node->value;
      }
    }

    return nullptr;
  }

  void remove(const T& value) {
    _root = remove_impl(std::move(_root), value);
  }

private:
  std::unique_ptr<AvlNode<T>> _root{};

private:
  //      N2                N3
  //     /  \              /  \
  //   N1    N3    ->    N2    N5
  //        /  \        /  \
  //      N4    N5    N1    N4
  static std::unique_ptr<AvlNode<T>> rotate_left(std::unique_ptr<AvlNode<T>> n2) {
    auto n3 = std::move(n2->_right);
    n2->_right = std::move(n3->_left);
    n2->update_height();
    n3->_left = std::move(n2);
    n3->update_height();
    return n3;
  }

  //        N3          N2
  //       /  \        /  \
  //     N2    N5 -> N1    N3
  //    /  \              /  \
  //  N1    N4          N4    N5
  static std::unique_ptr<AvlNode<T>> rotate_right(std::unique_ptr<AvlNode<T>> n3) {
    auto n2 = std::move(n3->_left);
    n3->_left = std::move(n2->_right);
    n3->update_height();
    n2->_right = std::move(n3);
    n2->update_height();
    return n2;
  }


  static std::unique_ptr<AvlNode<T>> rebalance(std::unique_ptr<AvlNode<T>> node) {
    node->update_height();

    if(node->balance() == 2) {
      if(node->_right->balance() < 0) {
        node->_right = rotate_right(std::move(node->_right));
      }

      return rotate_left(std::move(node));
    }

    if(node->balance() == -2) {
      if(node->_left->balance() > 0) {
        node->_left = rotate_left(std::move(node->_left));
      }

      return rotate_right(std::move(node));
    }

    return node;
  }

  static std::unique_ptr<AvlNode<T>> insert_impl(std::unique_ptr<AvlNode<T>> node, const T& value) {
    if(! node) {
      return std::make_unique<AvlNode<T>>(value);
    }

    if(value < node->value) {
      node->_left = insert_impl(std::move(node->_left), value);
    } else if(node->value < value) {
      node->_right = insert_impl(std::move(node->_right), value);
    } else {
      return node;
    }

    return rebalance(std::move(node));
  }

  static AvlNode<T>* find_min(AvlNode<T>* node) {
    while(node->_left) {
      node = node->_left.get();
    }

    return node;
  }

  static std::unique_ptr<AvlNode<T>> remove_impl(std::unique_ptr<AvlNode<T>> node, const T& value) {
    if(! node) {
      return nullptr;
    }

    if(value < node->value) {
      node->_left = remove_impl(std::move(node->_left), value);
    } else if(node->value < value) {
      node->_right = remove_impl(std::move(node->_right), value);
    } else {
      if(! node->_left) {
        return std::move(node->_right);
      }

      if(! node->_right) {
        return std::move(node->_left);
      }

      AvlNode<T>* successor = find_min(node->_right.get());
      node->value = successor->value;
      node->_right = remove_impl(std::move(node->_right), successor->value);
    }

    return rebalance(std::move(node));
  }
};
