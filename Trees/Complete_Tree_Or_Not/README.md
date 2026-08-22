# Check Completeness of a Binary Tree

## Problem

Given the root of a binary tree, determine whether the tree is a **complete binary tree**.

A binary tree is complete if:

1. Every level, except possibly the last, is completely filled.
2. All nodes in the last level are as far **left as possible**.

### Example — Complete Tree

```text
        1
       / \
      2   3
     / \  /
    4  5 6
```

Level-order traversal:

```text
1 2 3 4 5 6
```

This is a complete binary tree.

### Example — Not Complete

```text
        1
       / \
      2   3
       \   \
        5   7
```

There is a missing position before existing nodes on the same level, so the tree is not complete.

---

## Approach

This solution uses **Breadth-First Search (BFS)** with a queue.

During level-order traversal, we push both children of every node into the queue, including `NULL` children.

The important observation is:

> Once we encounter the first `NULL` position during BFS, every node that comes afterward must also be `NULL`.

If we encounter a non-NULL node after finding a `NULL`, the tree is not complete.

---

## Algorithm

1. Create a queue and push the root.
2. Maintain a boolean variable:

   ```cpp
   isNullFound = false;
   ```
3. Process nodes using BFS.
4. If the current node is `NULL`:

   * Set `isNullFound = true`.
5. If the current node is not `NULL`:

   * If `isNullFound` is already `true`, return `false`.
   * Otherwise, push its left and right children into the queue.
6. If traversal finishes without finding a non-NULL node after a `NULL`, return `true`.

---

## Code

```cpp
class Solution {
public:

    bool fun(TreeNode* root, bool &isNullFound) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* t = q.front();
            q.pop();

            // Found an empty position
            if (t == NULL) {
                isNullFound = true;
            }
            else {

                // A node appears after an empty position
                if (isNullFound == true) {
                    return false;
                }

                // Add children of current node
                q.push(t->left);
                q.push(t->right);
            }
        }

        return isNullFound;
    }

    bool isCompleteTree(TreeNode* root) {

        bool isNullFound = false;

        bool ans = fun(root, isNullFound);

        return ans;
    }
};
```

---

## How BFS Detects Completeness

Consider:

```text
        1
       / \
      2   3
     / \ /
    4  5 6
```

The BFS queue processes:

```text
1
↓
2 3
↓
4 5 6 NULL
↓
NULL NULL NULL NULL
```

The first `NULL` is found after all valid nodes have appeared.

Once `NULL` is found:

```text
isNullFound = true
```

Only `NULL` nodes should appear afterward.

Therefore, the tree is complete.

---

## Invalid Example

Consider:

```text
        1
       / \
      2   3
       \   \
        5   7
```

BFS processes the nodes approximately as:

```text
1 2 3 NULL 5 NULL 7
```

When `NULL` is encountered:

```text
isNullFound = true
```

But later we encounter:

```text
5
```

which is a valid node.

Therefore:

```cpp
if (isNullFound == true) {
    return false;
}
```

The tree is not complete.

---

## Important Correction: Use `t`, Not `root`

Inside the BFS loop, the current node is:

```cpp
TreeNode* t = q.front();
```

Therefore, we must push:

```cpp
q.push(t->left);
q.push(t->right);
```

and **not**:

```cpp
q.push(root->left);
q.push(root->right);
```

Using `root` repeatedly would keep adding the root's children to the queue and could cause the queue to grow indefinitely, resulting in **Memory Limit Exceeded**.

---

## Why `NULL` Nodes Are Added to the Queue

Consider:

```text
        1
       / \
      2   3
     /
    4
```

BFS needs to know that node `2` has a missing right child.

So we push:

```text
4 NULL
```

The queue eventually becomes:

```text
4 NULL NULL NULL
```

The first `NULL` tells us that an empty position has appeared.

From this point onward, there must be no valid nodes.

This is how we detect whether the last level is filled from left to right.

---

## Edge Cases

### Empty Tree

```text
root = NULL
```

An empty tree is generally considered complete.

However, the current implementation returns:

```text
false
```

because `isNullFound` becomes `true` and the function returns it only after processing the `NULL`.

If you want the conventional LeetCode behavior, you can explicitly handle it:

```cpp
if (root == NULL) {
    return true;
}
```

---

### Single Node

```text
    1
```

BFS:

```text
1 NULL NULL
```

The tree is complete.

Output:

```text
true
```

---

## Improved Version

The same approach can be written more simply by keeping `isNullFound` local to the function:

```cpp
class Solution {
public:

    bool isCompleteTree(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool isNullFound = false;

        while (!q.empty()) {

            TreeNode* t = q.front();
            q.pop();

            if (t == NULL) {
                isNullFound = true;
            }
            else {

                if (isNullFound) {
                    return false;
                }

                q.push(t->left);
                q.push(t->right);
            }
        }

        return true;
    }
};
```

This version avoids the extra `fun()` function and the reference parameter.

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Each node is processed once.

### Space Complexity

```text
O(n)
```

The queue can contain up to `O(n)` nodes/null positions in the worst case.

For a balanced tree, the queue typically contains `O(n)` nodes at the widest level in the worst case, which is `O(n)` asymptotically.

---

## Key Concepts

* Binary Tree
* Breadth-First Search (BFS)
* Level-Order Traversal
* Queue
* Complete Binary Tree
* `NULL` Position Tracking
* Boolean State

---

## Pattern

```text
                 BFS
                  ↓
          Process current node
                  ↓
            Is node NULL?
             ↙         ↘
           Yes          No
            ↓            ↓
     isNullFound=true   Was NULL found?
                          ↙      ↘
                        Yes       No
                         ↓         ↓
                      false    Add children
```

The core rule is:

```text
First NULL encountered
        ↓
No non-NULL node is allowed afterward
```

---

## Takeaway

The key idea is to use **BFS and treat NULL children as empty positions**.

For a complete binary tree, once an empty position appears during level-order traversal, **all subsequent positions must also be empty**.

The most important condition is:

```cpp
if (isNullFound) {
    return false;
}
```

And remember to enqueue:

```cpp
q.push(t->left);
q.push(t->right);
```

because `t` represents the **current node being processed**.
