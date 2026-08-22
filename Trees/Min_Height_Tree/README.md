# Minimum Depth of Binary Tree

## Problem

Given the root of a binary tree, return its **minimum depth**.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest **leaf node**.

A leaf node is a node that has no left or right child.

### Example

```text
        3
       / \
      9   20
         /  \
        15   7
```

The paths from the root to the leaf nodes are:

```text
3 → 9
3 → 20 → 15
3 → 20 → 7
```

The shortest path is:

```text
3 → 9
```

Therefore:

```text
Output: 2
```

---

## Approach

This solution uses **Depth-First Search (DFS)** with recursion.

The important part of this problem is that we must find the shortest path to a **leaf**, not simply the minimum depth between the left and right subtrees.

Therefore, we need to handle three situations:

1. The current node is `NULL`.
2. The current node has only a right child.
3. The current node has only a left child.
4. The current node has both children.

---

## Algorithm

### Case 1: Empty Tree

If:

```cpp
root == NULL
```

return:

```cpp
0
```

### Case 2: Only Right Child Exists

If:

```cpp
root->left == NULL
```

we cannot use the left subtree because it does not contain a leaf path.

So we must go through the right subtree:

```cpp
return 1 + minDepth(root->right);
```

### Case 3: Only Left Child Exists

If:

```cpp
root->right == NULL
```

we must go through the left subtree:

```cpp
return 1 + minDepth(root->left);
```

### Case 4: Both Children Exist

Now both subtrees contain possible paths to a leaf.

We calculate:

```cpp
left = minDepth(root->left);
right = minDepth(root->right);
```

Then choose the smaller one:

```cpp
return 1 + min(left, right);
```

---

## Code

```cpp
class Solution {
public:

    int minDepth(TreeNode* root) {

        // Empty tree
        if (root == NULL) {
            return 0;
        }

        // Only right subtree exists
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // Only left subtree exists
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // Both subtrees exist
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + min(left, right);
    }
};
```

---

## Why We Cannot Simply Use `min()`

A common mistake is to write:

```cpp
return 1 + min(minDepth(root->left),
               minDepth(root->right));
```

without handling `NULL` children.

Consider:

```text
        1
       /
      2
     /
    3
```

At node `1`:

```text
left = 2
right = 0
```

If we simply use `min()`:

```text
1 + min(2, 0)
= 1
```

But the correct minimum depth is:

```text
1 → 2 → 3
```

which is `3`.

The right side is `NULL`, so it is **not a valid path to a leaf**.

That is why the solution first checks:

```cpp
if (root->left == NULL)
```

and:

```cpp
if (root->right == NULL)
```

---

## Example Walkthrough

Consider:

```text
        1
       / \
      2   3
           \
            4
```

Start at node `1`.

Both children exist, so calculate:

```text
left = minDepth(2)
right = minDepth(3)
```

Node `2` is a leaf:

```text
minDepth(2) = 1
```

Node `3` has no left child:

```text
minDepth(3)
= 1 + minDepth(4)
```

Node `4` is a leaf:

```text
minDepth(4) = 1
```

Therefore:

```text
minDepth(3) = 2
```

Finally:

```text
minDepth(1)
= 1 + min(1, 2)
= 2
```

So the shortest path is:

```text
1 → 2
```

Output:

```text
2
```

---

## Important Difference from Maximum Depth

### Maximum Depth

For maximum depth, we can safely use:

```cpp
1 + max(left, right)
```

because a `NULL` subtree has depth `0`, and we are looking for the longest path.

### Minimum Depth

For minimum depth, we **cannot** blindly use:

```cpp
1 + min(left, right)
```

because a `NULL` subtree would incorrectly appear to be the shortest path.

We must ensure that the chosen path actually reaches a **leaf node**.

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Every node may be visited once.

### Space Complexity

```text
O(h)
```

where `h` is the height of the tree.

This is due to the recursive call stack.

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

### Only Left Children

```text
    1
   /
  2
 /
3
```

Output:

```text
3
```

### Only Right Children

```text
1
 \
  2
   \
    3
```

Output:

```text
3
```

---

## Key Concepts

* Binary Tree
* DFS
* Recursion
* Minimum Depth
* Leaf Node
* Tree Traversal
* Base Cases
* Handling `NULL` Children

---

## Pattern

```text
                  Root
                    ↓
               Is root NULL?
                ↙       ↘
              Yes        No
               ↓          ↓
             return    Check children
                0          ↓
                    ┌──────┴──────┐
                    ↓             ↓
              One child       Both children
                    ↓             ↓
              Follow that     Find both depths
                 child              ↓
                    ↓        1 + min(left, right)
             1 + child depth
```

---

## Takeaway

The key lesson in **Minimum Depth of Binary Tree** is that the minimum depth must always end at a **leaf node**.

Therefore, when one child is `NULL`, we must follow the other child instead of treating the `NULL` subtree as a valid path.

The core logic is:

```cpp
if (root->left == NULL)
    return 1 + minDepth(root->right);

if (root->right == NULL)
    return 1 + minDepth(root->left);

return 1 + min(minDepth(root->left),
               minDepth(root->right));
```

This `NULL`-child handling is the most important difference between finding the **minimum** and **maximum** depth of a binary tree.
