# Inorder Traversal

## Overview

This implementation performs an inorder traversal of a binary tree using recursion.

The traversal follows:

Left → Root → Right

## Approach

A recursive helper function is used to visit every node.

For each node:

1. Traverse the left subtree.
2. Store the current node's value.
3. Traverse the right subtree.

### Recursive Structure

```cpp
void fun(TreeNode* root, vector<int>& temp) {
    if (root == NULL) {
        return;
    }

    fun(root->left, temp);
    temp.push_back(root->val);
    fun(root->right, temp);
}
