#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */
#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  char _letter = 0;
  bool _end = false;

  std::shared_ptr<Node> _parent = nullptr;
  std::shared_ptr<Node> _failure = nullptr;

  std::unordered_map<char, std::shared_ptr<Node>> _children;
  std::vector<std::string> _outputs;
};

inline std::ostream& operator<<(std::ostream& out, const Node& node) {
  out << "Node(" << static_cast<const void*>(&node)
      << ", letter=" << (node._letter ? node._letter : '_')
      << ", end=" << node._end
      << ", children=" << node._children.size()
      << ")";
  return out;
}

struct AhoCorasick {
  AhoCorasick()
      : _root(std::make_shared<Node>()) {
    _root->_failure = _root;
  }

  AhoCorasick(const AhoCorasick&) = delete;
  AhoCorasick& operator=(const AhoCorasick&) = delete;

  AhoCorasick(AhoCorasick&& other) noexcept
      : AhoCorasick() {
    std::swap(_root, other._root);
  }

  AhoCorasick& operator=(AhoCorasick&& other) noexcept {
    std::swap(_root, other._root);
    return *this;
  }

  void insert(const std::string& word) {
    std::shared_ptr<Node> node = _root;

    for(const char letter : word) {
      const auto it = node->_children.find(letter);

      if(it == node->_children.end()) {
        std::shared_ptr<Node> child = std::make_shared<Node>();
        child->_letter = letter;
        child->_parent = node;
        node->_children.insert({letter, child});
        node = child;
      } else {
        node = it->second;
      }
    }

    node->_end = true;
    node->_outputs.push_back(word);
  }

  void build() {
    std::queue<std::shared_ptr<Node>> q;

    for(auto& [c, child] : _root->_children) {
      child->_failure = _root;
      q.push(child);
    }

    while(! q.empty()) {
      std::shared_ptr<Node> node = q.front();
      q.pop();

      for(auto& [c, child] : node->_children) {
        q.push(child);

        std::shared_ptr<Node> f = node->_failure;

        while(f != _root && ! f->_children.count(c)) {
          f = f->_failure;
        }

        if(f->_children.count(c)) {
          child->_failure = f->_children[c];
        } else {
          child->_failure = _root;
        }

        for(const auto& w : child->_failure->_outputs) {
          child->_outputs.push_back(w);
        }
      }
    }
  }

  void search(
      const std::string& text,
      const std::function<void(size_t, const std::string&)>& on_match
  ) const {
    std::shared_ptr<Node> node = _root;

    for(size_t i = 0; i < text.size(); ++i) {
      const char c = text[i];

      while(node != _root && ! node->_children.count(c)) {
        node = node->_failure;
      }

      if(node->_children.count(c)) {
        node = node->_children.at(c);
      }

      for(const auto& word : node->_outputs) {
        const size_t pos = i + 1 - word.size();
        on_match(pos, word);
      }
    }
  }

  void dump() const {
    _dump(0, _root);
  }

private:
  static void _dump(const int indent, const std::shared_ptr<Node>& node) {
    std::cout << std::string(indent, ' ') << *node << std::endl;

    for(const auto& [c, child] : node->_children) {
      _dump(indent + 2, child);
    }
  }

private:
  std::shared_ptr<Node> _root;
};
