# Maximum Depth of Binary Tree

## Problem

Given the root of a binary tree, return its **maximum depth**.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example

```text
        3
       / \
      9   20
         /  \
        15   7
```

The longest paths are:

```text
3 → 20 → 15
3 → 20 → 7
```

Each path contains `3` nodes.

Therefore:

```text
Output: 3
```

---

## Approach

This solution uses **Depth-First Search (DFS)** with recursion.

For every node, we recursively calculate:

* The maximum depth of the left subtree.
* The maximum depth of the right subtree.

Then we take the larger of the two and add `1` for the current node.

The formula is:

```text
depth = 1 + max(leftDepth, rightDepth)
```

---

## Algorithm

1. If the current node is `NULL`, return `0`.
2. Recursively calculate the depth of the left subtree.
3. Recursively calculate the depth of the right subtree.
4. Take the maximum of the two depths.
5. Add `1` for the current node.
6. Return the result.

---

## Code

```cpp
class Solution {
public:

    int maxDepth(TreeNode* root) {

        // Empty tree
        if (root == NULL) {
            return 0;
        }

        // Maximum depth of left subtree
        int left = maxDepth(root->left);

        // Maximum depth of right subtree
        int right = maxDepth(root->right);

        // Include current node
        return 1 + max(left, right);
    }
};
```

---

## How It Works

Consider this tree:

```text
        1
       / \
      2   3
     /
    4
```

Starting from node `1`:

```text
maxDepth(1)
    ↓
maxDepth(2)
    ↓
maxDepth(4)
```

Node `4` has no children:

```text
maxDepth(4) = 1
```

Therefore node `2` has:

```text
left = 1
right = 0

depth = 1 + max(1, 0)
      = 2
```

For node `3`:

```text
left = 0
right = 0

depth = 1
```

Finally, node `1`:

```text
left = 2
right = 1

depth = 1 + max(2, 1)
      = 3
```

Therefore:

```text
Output: 3
```

---

## Base Case

The most important base case is:

```cpp
if (root == NULL) {
    return 0;
}
```

An empty tree has a depth of `0`.

This also allows the recursion to correctly calculate the depth of leaf nodes.

For a leaf:

```text
    5
   / \
 NULL NULL
```

Both recursive calls return `0`:

```text
left = 0
right = 0
```

Then:

```text
1 + max(0, 0) = 1
```

So a leaf node has depth `1`.

---

## Recursion Formula

The entire solution can be represented by:

```text
             Depth(node)
                  |
          1 + max( / , \ )
                  |
          ┌───────┴───────┐
      left depth      right depth
```

Or mathematically:

```text
depth(root) = 1 + max(depth(root->left),
                       depth(root->right))
```

with the base case:

```text
depth(NULL) = 0
```

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Every node is visited exactly once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

The space is used by the recursive call stack.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

---

## Important Edge Cases

### Empty Tree

```text
root = NULL
```

Output:

```text
0
```

### Single Node

```text
    1
```

Output:

```text
1
```

### Completely Skewed Tree

```text
1
 \
  2
   \
    3
     \
      4
```

Output:

```text
4
```

---

## Key Concepts

* Binary Tree
* DFS
* Recursion
* Tree Height
* Divide and Conquer
* Base Case
* Recursive Call Stack

---

## Pattern

```text
              Root
               ↓
        Is root NULL?
          ↙       ↘
        Yes        No
         ↓          ↓
       return    Find left depth
         0            ↓
                  Find right depth
                       ↓
               max(left, right)
                       ↓
                 Add current node
                       ↓
              1 + max(left, right)
```

---

## Takeaway

The key idea is that the **maximum depth of a tree depends on the deeper of its two subtrees**.

For every node:

```cpp
return 1 + max(left, right);
```

The `1` represents the current node, while `max(left, right)` gives the depth of the deeper subtree.

This is one of the fundamental recursion patterns for solving **binary tree problems**.
