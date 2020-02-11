#include "tree.h"
#include <iostream>

bool Tree::empty() { return root_ == nullptr; }

int Tree::size() { return 0; }

void Tree::InOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  InOrder(start->left);
  std::cout << "val: " << start->val << std::endl;
  InOrder(start->right);
};

void Tree::PreOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  std::cout << "val: " << start->val << std::endl;
  PreOrder(start->left);
  PreOrder(start->right);
};

void Tree::PostOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  PostOrder(start->left);
  PostOrder(start->right);
  std::cout << "val: " << start->val << std::endl;
};

void Tree::CreateSampleTree1() {
  root_ = new TreeNode(60, new TreeNode(20), new TreeNode(80));
}

void Tree::CreateSampleTree2() {
  root_ = new TreeNode(
      60,
      new TreeNode(20, new TreeNode(10),
                   new TreeNode(30, new TreeNode(25), new TreeNode(50))),
      new TreeNode(80));
}
