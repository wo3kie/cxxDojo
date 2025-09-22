#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>


struct Node {
  char _letter = 0;
  bool _end = false;
  std::shared_ptr<Node> _parent = nullptr;
  std::shared_ptr<Node> _failure = nullptr;
  std::unordered_map<char, std::shared_ptr<Node>> _children;
};

inline std::ostream& operator<<(std::ostream& out, const Node& node) {
  if(node._parent) {
    out << "(" << (&node) << ", " << node._letter << ", " << node._end << ", (" << node._failure << ", " << node._failure->_letter << "))";
  } else {
    out << "(" << (&node) << ", , , (,)))";
  }

  return out;
}

inline std::string getWord(std::shared_ptr<Node> node) {
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
      : _root(std::make_shared<Node>()) {
    _root->_failure = _root;
  }

  AhoCorasick(const AhoCorasick&) = delete;
  AhoCorasick(AhoCorasick&& other)
      : AhoCorasick() {
    std::swap(_root, other._root);
  }

  ~AhoCorasick() {
  }

  AhoCorasick& operator=(const AhoCorasick&) = delete;
  AhoCorasick& operator=(AhoCorasick&& other) {
    std::swap(_root, other._root);
    return *this;
  }

  void insert(const std::string& word) {
    std::shared_ptr<Node> node = _root;

    for(const char letter : word) {
      const auto found = node->_children.find(letter);

      if(found == node->_children.end()) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
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
    std::shared_ptr<Node> node = _root;

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
  std::shared_ptr<Node> move(std::shared_ptr<Node> node, const char letter) const {
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

  std::shared_ptr<Node> getFailure(std::shared_ptr<Node> node, const char letter) {
    std::shared_ptr<Node> const parent = node->_parent;
    std::shared_ptr<Node> parentsFailure = parent->_failure;

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

  static void _dump(const int indent, std::shared_ptr<Node> node) {
    std::cout << std::string(indent, ' ') << *node << std::endl;

    for(const auto pair : node->_children) {
      _dump(indent + 4, pair.second);
    }
  }

private:
  std::shared_ptr<Node> _root;
};
