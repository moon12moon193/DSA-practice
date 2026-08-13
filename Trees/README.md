# Tree Data Structure

## Introduction

A **Tree** is a non-linear data structure used to represent hierarchical relationships between elements.

Unlike arrays and linked lists, trees do not store elements sequentially. Instead, elements are connected through **nodes and edges**.

A tree consists of:

* **Nodes** — store data.
* **Edges** — connect nodes.
* **Root** — the starting/top node.
* **Parent** — a node that has one or more children.
* **Child** — a node connected below a parent.
* **Leaf** — a node with no children.
* **Subtree** — a tree formed from a node and its descendants.

---

## Basic Tree Structure

A simple binary tree can look like:

```text
        1
       / \
      2   3
     / \
    4   5
```

Here:

```text
1 → Root
2, 3 → Children of 1
4, 5 → Children of 2
4, 5, 3 → Leaf nodes
```

---

# Binary Tree

A **Binary Tree** is a tree in which each node can have at most two children:

```text
Left Child
Right Child
```

A typical node can be represented as:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
```

Example:

```text
        10
       /  \
      5    15
     / \     \
    2   7     20
```

---

# Important Tree Terminology

### Root

The topmost node.

```text
        10
```

### Parent

A node directly above another node.

```text
        10
       /
      5
```

`10` is the parent of `5`.

### Child

A node directly below another node.

`5` is a child of `10`.

### Leaf

A node that has no children.

```text
    2
```

is a leaf in the example above.

### Height

The longest path from a node to a leaf.

### Depth

The distance from the root to a particular node.

### Subtree

A node together with all of its descendants.

---

# Tree Traversal

Traversal means visiting all nodes of a tree in a particular order.

The major traversal techniques are:

1. **Preorder**
2. **Inorder**
3. **Postorder**
4. **Level Order**

---

# Preorder Traversal

The order is:

```text
Root → Left → Right
```

For:

```text
        1
       / \
      2   3
     / \
    4   5
```

the traversal is:

```text
1 → 2 → 4 → 5 → 3
```

Recursive structure:

```cpp
void preorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    // Process root

    preorder(root->left);

    preorder(root->right);
}
```

---

# Inorder Traversal

The order is:

```text
Left → Root → Right
```

For the same tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

the traversal is:

```text
4 → 2 → 5 → 1 → 3
```

Recursive structure:

```cpp
void inorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    // Process root

    inorder(root->right);
}
```

---

# Postorder Traversal

The order is:

```text
Left → Right → Root
```

For the same tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

the traversal is:

```text
4 → 5 → 2 → 3 → 1
```

Recursive structure:

```cpp
void postorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    // Process root
}
```

---

# Level Order Traversal

Level order visits nodes level by level.

For:

```text
        1
       / \
      2   3
     / \
    4   5
```

the order is:

```text
1 → 2 → 3 → 4 → 5
```

This is commonly implemented using a **queue**.

```cpp
queue<TreeNode*> q;

q.push(root);

while (!q.empty()) {

    TreeNode* curr = q.front();
    q.pop();

    // Process curr

    if (curr->left != NULL) {
        q.push(curr->left);
    }

    if (curr->right != NULL) {
        q.push(curr->right);
    }
}
```

---

# Recursion in Trees

Trees and recursion are strongly connected because every child can itself be considered the root of a smaller tree.

For example:

```text
        1
       / \
      2   3
```

The left subtree is:

```text
    2
```

and the right subtree is:

```text
    3
```

Therefore, many tree algorithms follow:

```text
Solve current node
        ↓
Solve left subtree
        ↓
Solve right subtree
```

The most important base case is usually:

```cpp
if (root == NULL) {
    return;
}
```

---

# Binary Search Tree

A **Binary Search Tree (BST)** follows an ordering property:

```text
Left subtree values < Root < Right subtree values
```

Example:

```text
        8
       / \
      4   12
     / \  / \
    2  6 10 14
```

This ordering allows searching to eliminate half of the tree at each step when the tree is balanced.

---

# Tree Types

While learning trees, important structures include:

* Binary Tree
* Binary Search Tree
* Balanced Tree
* Complete Binary Tree
* Full Binary Tree
* Perfect Binary Tree
* Heap
* Trie
* AVL Tree

Each has different structural properties and use cases.

---

# Common Tree Techniques

As you progress through tree problems, focus on these patterns:

### 1. Recursive Traversal

```text
Root
 ↓
Left subtree
 ↓
Right subtree
```

### 2. Depth-Based Problems

Use recursion to calculate information from child nodes and return it to the parent.

### 3. Tree Construction

Build a tree from given information while maintaining the correct parent-child relationships.

### 4. Tree Comparison

Recursively compare corresponding nodes of two trees.

### 5. Path-Based Problems

Track information while moving from the root toward descendants.

### 6. Level-Based Processing

Use a queue when the problem requires processing nodes level by level.

### 7. BST Properties

Use the ordering property of a Binary Search Tree to reduce unnecessary traversal.

---

# Complexity

For a tree containing `n` nodes:

### Traversal

A standard traversal visits every node once:

```text
Time: O(n)
```

For recursive traversal:

```text
Space: O(h)
```

where `h` is the height of the tree because of the recursion stack.

For a balanced tree:

```text
h = O(log n)
```

For a completely skewed tree:

```text
h = O(n)
```

---

# Important Learning Pattern

Most recursive tree algorithms can initially be understood using this structure:

```cpp
ReturnType solve(TreeNode* root) {

    // Base case
    if (root == NULL) {
        // return appropriate value
    }

    // Solve left subtree
    ReturnType left = solve(root->left);

    // Solve right subtree
    ReturnType right = solve(root->right);

    // Combine results
}
```

The key question to ask is:

> **What information should the current node receive from its left and right subtrees?**

Once this becomes clear, many tree problems become much easier to approach.

---

# Key Takeaways

* Trees are **non-linear hierarchical data structures**.
* A binary tree has at most two children per node.
* `left` and `right` pointers represent the two children.
* Tree algorithms frequently use **recursion**.
* Always identify the `NULL` base case.
* Understand preorder, inorder, postorder, and level order traversal.
* Learn to think of every subtree as a smaller tree.
* Use a queue for level-order processing.
* Use BST ordering to optimize searching.
* Always consider the tree's height when analyzing recursive space complexity.

---

## Learning Focus

The recommended progression while learning trees is:

```text
Tree Basics
     ↓
Binary Trees
     ↓
Tree Traversals
     ↓
Recursion on Trees
     ↓
Height / Depth
     ↓
Path-Based Techniques
     ↓
Tree Construction
     ↓
Binary Search Trees
     ↓
Level Order / BFS
     ↓
Advanced Tree Techniques
```

This folder contains your **Tree Data Structure practice and implementations**, organized as you progress from fundamental concepts to more advanced tree techniques.
