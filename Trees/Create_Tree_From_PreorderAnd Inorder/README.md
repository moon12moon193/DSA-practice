# Construct Binary Tree from Preorder and Inorder Traversal

## Problem

Given two integer arrays:

* `preorder` — the preorder traversal of a binary tree.
* `inorder` — the inorder traversal of the same binary tree.

Construct and return the **binary tree**.

### Traversal Orders

**Preorder:**

```text
Root → Left → Right
```

**Inorder:**

```text
Left → Root → Right
```

### Example

```text
preorder = [3, 9, 20, 15, 7]

inorder = [9, 3, 15, 20, 7]
```

The tree is:

```text
        3
       / \
      9   20
         /  \
        15   7
```

---

## Key Observation

The most important observation is:

### 1. Preorder tells us the root

Preorder follows:

```text
Root → Left → Right
```

Therefore, the **first element** of the preorder array is always the root of the current subtree.

For:

```text
preorder = [3, 9, 20, 15, 7]
```

the root is:

```text
3
```

After using `3`, the next unused preorder value belongs to the left or right subtree depending on the inorder positions.

---

### 2. Inorder separates left and right subtrees

Inorder follows:

```text
Left → Root → Right
```

For:

```text
inorder = [9, 3, 15, 20, 7]
```

the root `3` is at index `1`.

Therefore:

```text
Left subtree  = [9]
Right subtree = [15, 20, 7]
```

This allows us to determine exactly which nodes belong to each subtree.

---

## Approach

The solution uses:

* **Recursion**
* **Preorder traversal**
* **Inorder traversal**
* **Hash Map**
* **Divide and Conquer**

We create a hash map:

```cpp
unordered_map<int, int> f;
```

which stores:

```text
value → index in inorder
```

For example:

```text
inorder = [9, 3, 15, 20, 7]
```

The map becomes:

```text
9  → 0
3  → 1
15 → 2
20 → 3
7  → 4
```

This lets us find the position of every root in `O(1)` average time.

---

## Algorithm

1. Store every value's index from `inorder` in a hash map.
2. Start with `index = 0` in the preorder array.
3. The current `preorder[index]` is the root of the current subtree.
4. Create a new `TreeNode`.
5. Find the root's position in `inorder`.
6. Everything before that position belongs to the left subtree.
7. Everything after that position belongs to the right subtree.
8. Recursively construct the left subtree.
9. Recursively construct the right subtree.
10. Return the constructed root.

---

## Code

```cpp
class Solution {
public:

    TreeNode* fun(vector<int>& preorder,
                  unordered_map<int, int>& f,
                  int &index,
                  int low,
                  int high) {

        // No elements in this subtree
        if (low > high) {
            return NULL;
        }

        // Preorder gives the root
        TreeNode* root = new TreeNode(preorder[index]);

        index++;

        // Find root position in inorder
        int id = f[root->val];

        // Build left subtree
        root->left = fun(
            preorder,
            f,
            index,
            low,
            id - 1
        );

        // Build right subtree
        root->right = fun(
            preorder,
            f,
            index,
            id + 1,
            high
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        // Store inorder value → index
        unordered_map<int, int> f;

        for (int i = 0; i < inorder.size(); i++) {
            f[inorder[i]] = i;
        }

        int index = 0;

        int low = 0;
        int high = preorder.size() - 1;

        return fun(preorder, f, index, low, high);
    }
};
```

---

## Dry Run

Consider:

```text
preorder = [3, 9, 20, 15, 7]

inorder = [9, 3, 15, 20, 7]
```

### Step 1 — Root

`index = 0`

```text
preorder[index] = 3
```

So:

```text
root = 3
```

In inorder:

```text
[9, 3, 15, 20, 7]
    ↑
    3
```

The index of `3` is `1`.

Therefore:

```text
left  → indices 0 to 0
right → indices 2 to 4
```

---

### Step 2 — Left Subtree

The next preorder value is:

```text
9
```

So:

```text
      3
     /
    9
```

`9` is at index `0` in inorder.

Its left range is:

```text
0 to -1
```

which is invalid, so:

```cpp
return NULL;
```

Its right range is also invalid.

Therefore `9` is a leaf.

---

### Step 3 — Right Subtree

The next preorder value is:

```text
20
```

So:

```text
      3
     / \
    9   20
```

`20` is at index `3` in inorder:

```text
[9, 3, 15, 20, 7]
          ↑
         20
```

Therefore:

```text
left  → index 2
right → index 4
```

The left subtree becomes:

```text
15
```

The right subtree becomes:

```text
7
```

Final tree:

```text
        3
       / \
      9   20
         /  \
        15   7
```

---

## Role of `index`

The variable:

```cpp
int &index
```

keeps track of the current position in the preorder array.

It is passed by reference so that every recursive call shares the same preorder position.

For example:

```text
preorder = [3, 9, 20, 15, 7]

index = 0 → 3
index = 1 → 9
index = 2 → 20
index = 3 → 15
index = 4 → 7
```

Every time a node is created:

```cpp
index++;
```

moves to the next root candidate.

---

## Role of `low` and `high`

The parameters:

```cpp
int low,
int high
```

represent the current range of the `inorder` array that belongs to the current subtree.

For example:

```text
inorder = [9, 3, 15, 20, 7]
```

For root `3`:

```text
low = 0
high = 4
```

Root index:

```text
id = 1
```

Therefore:

```text
Left subtree:
low = 0
high = 0

Right subtree:
low = 2
high = 4
```

This recursively divides the inorder array into smaller sections.

---

## Base Case

The base case is:

```cpp
if (low > high) {
    return NULL;
}
```

This means there are no elements available for the current subtree.

For example:

```text
low = 2
high = 1
```

Since:

```text
2 > 1
```

the subtree is empty.

---

## Why the Hash Map Is Used

Without a hash map, we would need to search for every root inside the inorder array.

That could make the solution slower.

The hash map stores:

```text
value → inorder index
```

so this operation:

```cpp
int id = f[root->val];
```

takes **O(1) average time**.

This makes the overall solution efficient.

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

```text
O(n)
```

Each node is created once, and its inorder position is found in `O(1)` average time using the hash map.

### Space Complexity

```text
O(n)
```

The hash map stores `n` values.

The recursion stack additionally uses:

```text
O(h)
```

where `h` is the height of the tree.

Therefore, the total auxiliary space is:

```text
O(n + h)
```

which is generally represented as:

```text
O(n)
```

---

## Important Edge Cases

### Empty Tree

```text
preorder = []
inorder = []
```

Then:

```text
high = -1
```

so:

```text
low > high
```

and the function returns `NULL`.

---

### Single Node

```text
preorder = [1]
inorder = [1]
```

The constructed tree is:

```text
    1
```

---

### Completely Skewed Tree

```text
preorder = [1, 2, 3, 4]
inorder  = [1, 2, 3, 4]
```

The result is:

```text
1
 \
  2
   \
    3
     \
      4
```

---

## Key Concepts

* Binary Tree
* Preorder Traversal
* Inorder Traversal
* Recursion
* Divide and Conquer
* Hash Map
* Tree Construction
* Pass by Reference
* Range-Based Recursion

---

## Pattern

```text
             Preorder
                 ↓
          Find Current Root
                 ↓
          Find Root in Inorder
                 ↓
        ┌────────┴────────┐
        ↓                 ↓
   Left Inorder      Right Inorder
      Range              Range
        ↓                 ↓
  Build Left          Build Right
    Recursively         Recursively
        └────────┬────────┘
                 ↓
            Return Root
```

---

## Takeaway

The key observation is:

```text
Preorder → tells us WHAT the root is
Inorder  → tells us WHERE the root divides the tree
```

For every subtree:

```cpp
TreeNode* root = new TreeNode(preorder[index]);
```

gets the root from preorder.

Then:

```cpp
int id = f[root->val];
```

finds the root's position in inorder.

Finally:

```cpp
root->left = fun(preorder, f, index, low, id - 1);

root->right = fun(preorder, f, index, id + 1, high);
```

recursively constructs the left and right subtrees.

This **Preorder + Inorder + Hash Map + Recursion** pattern is one of the most important binary-tree construction patterns to understand.
