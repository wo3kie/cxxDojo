/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/treeClassification
 */

#include <memory>

#include "./assert.hpp"

/*
 * Node
 */

struct Node {
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

/*
 * isFullTree
 */

bool isFullTree(const std::unique_ptr<Node>& node) {
  if(node == nullptr) {
    return false;
  }

  if(node->left == nullptr) {
    if(node->right == nullptr) {
      return true;
    } else {
      return false;
    }
  } else {
    if(node->right == nullptr) {
      return false;
    } else {
      return isFullTree(node->left) && isFullTree(node->right);
    }
  }
}
/*
 * isFullTree_test
 */

void isFullTree_test() {
  std::unique_ptr<Node> root;
  Assert(! isFullTree(root));

  // N
  root = std::make_unique<Node>();
  Assert(isFullTree(root));

  //   N
  // N
  root->left = std::make_unique<Node>();
  Assert(! isFullTree(root));

  //   N
  // N   N
  root->right = std::make_unique<Node>();
  Assert(isFullTree(root));

  //     N
  //   N   N
  // N
  root->left->left = std::make_unique<Node>();
  Assert(! isFullTree(root));

  //      N
  //   N     N
  // N   N
  root->left->right = std::make_unique<Node>();
  Assert(isFullTree(root));

  //       N
  //   N      N
  // N   N      N
  root->right->right = std::make_unique<Node>();
  Assert(! isFullTree(root));

  //       N
  //   N        N
  // N   N   N    N
  root->right->left = std::make_unique<Node>();
  Assert(isFullTree(root));
}

unsigned getLeftMostChildDepth(const std::unique_ptr<Node>& node) {
  if(node == nullptr) {
    return 0;
  }

  if(node->left == nullptr) {
    return 0;
  }

  return 1 + getLeftMostChildDepth(node->left);
}

bool isCompleteTreeImpl(const std::unique_ptr<Node>& node, unsigned currentDepth, unsigned& expectedDepth, bool& oneLevelUp) {
  if(node == nullptr) {
    return false;
  }

  if(currentDepth > expectedDepth) {
    return false;
  }

  if(node->left == nullptr) {
    if(node->right == nullptr) {
      if(oneLevelUp) {
        return currentDepth == expectedDepth;
      } else {
        if(currentDepth == expectedDepth) {
          return true;
        } else if(currentDepth + 1 == expectedDepth) {
          expectedDepth -= 1;
          oneLevelUp = true;
          return true;
        } else {
          return false;
        }
      }
    } else {
      return false;
    }
  } else {
    if(node->right == nullptr) {
      const bool result = isCompleteTreeImpl(node->left, currentDepth + 1, expectedDepth, oneLevelUp);

      oneLevelUp = true;
      expectedDepth -= 1;

      return result;
    } else {
      return isCompleteTreeImpl(node->left, currentDepth + 1, expectedDepth, oneLevelUp)
             && isCompleteTreeImpl(node->right, currentDepth + 1, expectedDepth, oneLevelUp);
    }
  }
}

bool isCompleteTree(const std::unique_ptr<Node>& node) {

  bool oneLevelUp = false;
  unsigned expectedDepth = getLeftMostChildDepth(node);

  return isCompleteTreeImpl(node, 0, expectedDepth, oneLevelUp);
}

void isCompleteTree_test() {
  std::unique_ptr<Node> root;
  Assert(! isFullTree(root));

  // N
  root = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //   N
  // N
  root->left = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //   N
  // N   N
  root->right = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //     N
  //   N   N
  // N
  root->left->left = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //      N
  //   N     N
  // N   N
  root->left->right = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //       N
  //   N      N
  // N   N      N
  root->right->right = std::make_unique<Node>();
  Assert(! isCompleteTree(root));

  //       N
  //   N       N
  // N   N   N   N
  root->right->left = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //         N
  //     N       N
  //   N   N   N   N
  // N
  root->left->left->left = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //          N
  //     N         N
  //   N   N     N   N
  // N         N
  root->right->left->left = std::make_unique<Node>();
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N     N      N     N
  // N   N        N
  root->left->left->right = std::make_unique<Node>();
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N     N      N     N
  // N   N N      N
  root->left->right->left = std::make_unique<Node>();
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N     N      N     N
  // N   N N   N  N
  root->left->right->right = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //            N
  //      N            N
  //   N     N      N     N
  // N   N N   N  N     N
  root->right->right->left = std::make_unique<Node>();
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N     N      N     N
  // N   N N   N  N   N N
  root->right->left->right = std::make_unique<Node>();
  Assert(isCompleteTree(root));

  //            N
  //      N            N
  //   N            N     N
  // N   N        N   N N
  root->left->right = nullptr;
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N            N
  // N   N        N   N
  root->right->right = nullptr;
  Assert(! isCompleteTree(root));

  //            N
  //      N            N
  //   N
  // N   N
  root->right->left = nullptr;
  Assert(! isCompleteTree(root));
}

/*
 * main
 */

int main() {
  isFullTree_test();
  isCompleteTree_test();
}
