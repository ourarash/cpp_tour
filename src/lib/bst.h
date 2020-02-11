#ifndef BST_TREE_H
#define BST_TREE_H

#include "tree.h"

class BST : public Tree {
public:
  BST() { root_ = nullptr; }
  bool empty();
  int size();

  void insert(TreeNode *&root, int v);
  TreeNode* search(TreeNode *root, int v);

  TreeNode *root_;
};

#endif