#include "bst.h"
#include <iostream>

bool BST::empty() { return root_ == nullptr; }

int BST::size() { return 0; }

void BST::insert(TreeNode *&root, int v) {
  if (root == nullptr) {
    root = new TreeNode(v);
  } else if (v < root->val) {
    insert(root->left, v);
  } else if (v > root->val) {
    insert(root->right, v);
  }
}

TreeNode *BST::search(TreeNode *root, int v) {
  if (root == nullptr) {
    return root;
  }
  if (root->val == v) {
    return root;
  }
  if (v < root->val) {
    return search(root->left, v);
  } else // v > root->val
  {
    return search(root->right, v);
  }
}
