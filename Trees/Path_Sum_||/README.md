# Path Sum II

## Problem

Given the root of a binary tree and an integer `targetSum`, return **all root-to-leaf paths** where the sum of the node values along the path equals `targetSum`.

A **leaf node** is a node that has no left or right child.

Each path should be returned as a list of node values.

### Example

```text
Input:

        5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1

targetSum = 22
```

The valid root-to-leaf path is:

```text
5 → 4 → 11 → 2
```

Therefore:

```text
Output:
[[5,4,11,2]]
```

---

## Approach

This solution uses **Depth-First Search (DFS)** with **backtracking**.

We maintain two important variables:

* `sum` → stores the sum of the current root-to-node path.
* `temp` → stores the nodes of the current path.

Whenever we reach a leaf node, we check whether the current `sum` equals `targetSum`.

If it does, we add the current path to `res`.

---

## Algorithm

1. Start DFS from the root.
2. If the current node is `NULL`, return.
3. Add the current node's value to `sum`.
4. Add the current node's value to `temp`.
5. Check if the current node is a leaf.
6. If it is a leaf and `sum == targetSum`, add `temp` to `res`.
7. Recursively explore the left subtree.
8. Recursively explore the right subtree.
9. Remove the current node from `temp` using `pop_back()`.
10. Continue exploring the remaining paths.

---

## Code

```cpp
class Solution {

    void fun(TreeNode* root,
             int targetSum,
             int sum,
             vector<int>& temp,
             vector<vector<int>>& res) {

        if (root == NULL) {
            return;
        }

        // Add current node to sum
        sum = sum + root->val;

        // Add current node to current path
        temp.push_back(root->val);

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            if (sum == targetSum) {
                res.push_back({temp});
            }
        }

        // Explore left subtree
        fun(root->left, targetSum, sum, temp, res);

        // Explore right subtree
        fun(root->right, targetSum, sum, temp, res);

        // Backtracking
        temp.pop_back();

        return;
    }

public:

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> res;
        vector<int> temp;

        int sum = 0;

        fun(root, targetSum, sum, temp, res);

        return res;
    }
};
```

---

## Understanding `temp`

The `temp` vector represents the **current root-to-node path**.

For example, while traversing:

```text
        5
       /
      4
     /
    11
```

The vector changes like this:

```text
temp = [5]

temp = [5, 4]

temp = [5, 4, 11]
```

When DFS finishes exploring node `11`, we perform:

```cpp
temp.pop_back();
```

Now:

```text
temp = [5, 4]
```

When we return to node `5` and explore another branch, the path is correctly maintained.

---

## Backtracking

Backtracking is the key concept in this solution.

These two operations work together:

```cpp
temp.push_back(root->val);
```

and later:

```cpp
temp.pop_back();
```

The process looks like:

```text
              5
             / \
            4   8
           /
          11

Visit 5:
temp = [5]

Visit 4:
temp = [5,4]

Visit 11:
temp = [5,4,11]

Finish 11:
temp = [5,4]

Finish 4:
temp = [5]

Visit 8:
temp = [5,8]
```

This allows the same vector to be reused for every possible path.

---

## Why `sum` Does Not Need Backtracking

Notice that the function receives:

```cpp
int sum
```

instead of:

```cpp
int &sum
```

Therefore, `sum` is passed **by value**.

Every recursive call gets its own copy of `sum`.

For example:

```text
fun(5)
    sum = 5

    fun(4)
        sum = 9

        fun(11)
            sum = 20
```

Changes made to `sum` inside one recursive call do not affect the parent call.

Therefore, this line:

```cpp
sum = sum - root->val;
```

is actually **not necessary** for `sum`.

The important backtracking operation is:

```cpp
temp.pop_back();
```

because `temp` is passed by reference:

```cpp
vector<int>& temp
```

---

## Complexity

Let `n` be the number of nodes in the tree.

### Time Complexity

Approximately:

```text
O(n × h)
```

where `h` is the height of the tree.

The DFS visits every node, and when a valid path is found, copying the path into `res` takes up to `O(h)` time.

### Space Complexity

```text
O(h)
```

for the recursion stack and current path.

Additionally, the result itself can require:

```text
O(n × h)
```

in the worst case because multiple valid paths may be stored.

---

## Key Concepts

* Binary Tree
* DFS
* Recursion
* Root-to-Leaf Path
* Backtracking
* Pass by Value
* Pass by Reference
* `vector<int>`
* `vector<vector<int>>`

---

## Important Difference from Path Sum I

### Path Sum I

Only asks:

```text
Does at least one valid path exist?
```

Return type:

```cpp
bool
```

### Path Sum II

Asks:

```text
What are all the valid paths?
```

Return type:

```cpp
vector<vector<int>>
```

So Path Sum II requires us to maintain the actual path using:

```cpp
vector<int> temp;
```

---

## Pattern

```text
              Binary Tree
                   ↓
                  DFS
                   ↓
        Maintain Current Path
                   ↓
          Maintain Current Sum
                   ↓
              Reach Leaf
                   ↓
        sum == targetSum ?
             ↙       ↘
           Yes        No
            ↓          ↓
       Store Path    Ignore
            ↓
        Backtrack
            ↓
      pop_back()
```

---

## Takeaway

The main idea is to use **DFS + backtracking** to explore every root-to-leaf path.

`sum` keeps track of the current path's sum, while `temp` keeps track of the actual nodes in that path. When a valid leaf is found, the path is copied into `res`. After exploring a node, `temp.pop_back()` removes that node so that the vector is ready for the next path.
