#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <functional>
#include <iostream>
#include <map>
#include <string>

namespace aho_corasick {

struct Node {
  void free() {
    for(const auto pair : _children) {
      pair.second->free();
    }

    delete this;
  }

  char _letter = 0;
  bool _end = false;
  Node* _parent = nullptr;
  Node* _failure = nullptr;
  std::map<char, Node*> _children;
};

inline std::ostream& operator<<(std::ostream& out, const Node& node) {
  if(node._parent) {
    out << "(" << (&node) << ", " << node._letter << ", " << node._end << ", (" << node._failure << ", " << node._failure->_letter << "))";
  } else {
    out << "(" << (&node) << ", , , (,)))";
  }

  return out;
}

inline std::string getWord(const Node* const node) {
  if(! node) {
    return "";
  }

  if(! node->_parent) {
    return "";
  }

  return getWord(node->_parent) + std::string(1, node->_letter);
}

struct AhoCorasick {
  AhoCorasick()
      : _root(new Node()) {
    _root->_failure = _root;
  }

  AhoCorasick(const AhoCorasick&) = delete;
  AhoCorasick(AhoCorasick&& other)
      : AhoCorasick() {
    std::swap(_root, other._root);
  }

  ~AhoCorasick() {
    _root->free();
  }

  AhoCorasick& operator=(const AhoCorasick&) = delete;
  AhoCorasick& operator=(AhoCorasick&& other) {
    std::swap(_root, other._root);
    return *this;
  }

  void insert(const std::string& word) {
    Node* node = _root;

    for(const char letter : word) {
      const auto found = node->_children.find(letter);

      if(found == node->_children.end()) {
        Node* const newNode = new Node;
        newNode->_letter = letter;
        newNode->_parent = node;
        newNode->_failure = getFailure(newNode, letter);

        node->_children.insert(std::make_pair(letter, newNode));
        node = newNode;
      } else {
        node = found->second;
      }
    }

    node->_end = true;
  }

  void search(const std::string& text, const std::function<void(const size_t, const std::string&)>& f) const {
    const Node* node = _root;

    for(size_t i = 0; i < text.size(); ++i) {
      node = move(node, text[i]);

      if(node->_end) {
        const std::string word = getWord(node);

        f(i + 1 - word.size(), word);
      }
    }
  }

  void dump() const {
    _dump(0, _root);
  }

private:
  const Node* move(const Node* node, const char letter) const {
    while(true) {
      const auto found = node->_children.find(letter);

      if(found == node->_children.end()) {
        if(node == _root) {
          return node;
        } else {
          node = node->_failure;
        }
      } else {
        return found->second;
      }
    }
  }

  Node* getFailure(const Node* const node, const char letter) {
    Node* const parent = node->_parent;
    Node* parentsFailure = parent->_failure;

    while(true) {
      const auto found = parentsFailure->_children.find(letter);

      if(found != parentsFailure->_children.end()) {
        return found->second;
      }

      if(parentsFailure == _root) {
        return _root;
      }

      parentsFailure = parentsFailure->_failure;
    }
  }

  static void _dump(const int indent, const Node* const node) {
    std::cout << std::string(indent, ' ') << *node << std::endl;

    for(const auto pair : node->_children) {
      _dump(indent + 4, pair.second);
    }
  }

private:
  Node* _root;
};

} // namespace aho_corasick
