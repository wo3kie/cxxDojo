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
    for(const auto pair : children_) {
      pair.second->free();
    }

    delete this;
  }

  char letter_ = 0;
  bool end_ = false;
  Node* parent_ = nullptr;
  Node* failure_ = nullptr;
  std::map<char, Node*> children_;
};

inline std::ostream& operator<<(std::ostream& out, const Node& node) {
  if(node.parent_) {
    out << "(" << (&node) << ", " << node.letter_ << ", " << node.end_ << ", (" << node.failure_ << ", " << node.failure_->letter_ << "))";
  } else {
    out << "(" << (&node) << ", , , (,)))";
  }

  return out;
}

inline std::string getWord(const Node* const node) {
  if(! node) {
    return "";
  }

  if(! node->parent_) {
    return "";
  }

  return getWord(node->parent_) + std::string(1, node->letter_);
}

struct AhoCorasick {
  AhoCorasick()
      : root_(new Node()) {
    root_->failure_ = root_;
  }

  AhoCorasick(const AhoCorasick&) = delete;
  AhoCorasick(AhoCorasick&& other)
      : AhoCorasick() {
    std::swap(root_, other.root_);
  }

  ~AhoCorasick() {
    root_->free();
  }

  AhoCorasick& operator=(const AhoCorasick&) = delete;
  AhoCorasick& operator=(AhoCorasick&& other) {
    std::swap(root_, other.root_);
    return *this;
  }

  void insert(const std::string& word) {
    Node* node = root_;

    for(const char letter : word) {
      const auto found = node->children_.find(letter);

      if(found == node->children_.end()) {
        Node* const newNode = new Node;
        newNode->letter_ = letter;
        newNode->parent_ = node;
        newNode->failure_ = getFailure(newNode, letter);

        node->children_.insert(std::make_pair(letter, newNode));
        node = newNode;
      } else {
        node = found->second;
      }
    }

    node->end_ = true;
  }

  void search(const std::string& text, const std::function<void(const size_t, const std::string&)>& f) const {
    const Node* node = root_;

    for(size_t i = 0; i < text.size(); ++i) {
      node = move(node, text[i]);

      if(node->end_) {
        const std::string word = getWord(node);

        f(i + 1 - word.size(), word);
      }
    }
  }

  void dump() const {
    dump_(0, root_);
  }

private:
  const Node* move(const Node* node, const char letter) const {
    while(true) {
      const auto found = node->children_.find(letter);

      if(found == node->children_.end()) {
        if(node == root_) {
          return node;
        } else {
          node = node->failure_;
        }
      } else {
        return found->second;
      }
    }
  }

  Node* getFailure(const Node* const node, const char letter) {
    Node* const parent = node->parent_;
    Node* parentsFailure = parent->failure_;

    while(true) {
      const auto found = parentsFailure->children_.find(letter);

      if(found != parentsFailure->children_.end()) {
        return found->second;
      }

      if(parentsFailure == root_) {
        return root_;
      }

      parentsFailure = parentsFailure->failure_;
    }
  }

  static void dump_(const int indent, const Node* const node) {
    std::cout << std::string(indent, ' ') << *node << std::endl;

    for(const auto pair : node->children_) {
      dump_(indent + 4, pair.second);
    }
  }

private:
  Node* root_;
};

} // namespace aho_corasick
