# Rotate List (LeetCode 61)

## Problem

Given the head of a singly linked list, rotate the list to the right by `k` places.

A right rotation moves the last node to the front of the list. This process is repeated `k` times.

Return the head of the rotated linked list.

---

## Example 1

**Input**

```cpp
head = [1,2,3,4,5]
k = 2
```

**Output**

```cpp
[4,5,1,2,3]
```

### Explanation

Original list

```
1 → 2 → 3 → 4 → 5
```

After one rotation

```
5 → 1 → 2 → 3 → 4
```

After two rotations

```
4 → 5 → 1 → 2 → 3
```

---

## Example 2

**Input**

```cpp
head = [0,1,2]
k = 4
```

**Output**

```cpp
[2,0,1]
```

---

# Intuition

Rotating the list one step at a time would be inefficient when `k` is very large.

Instead, we:

1. Find the length of the linked list.
2. Compute the effective number of rotations using `k % n`.
3. Find the new tail of the rotated list.
4. Make the last node point to the original head.
5. Break the list at the new tail.

This completes the rotation in a single traversal after finding the length.

---

# Approach

## Step 1: Handle Edge Cases

If the list is empty or contains only one node, no rotation is needed.

```cpp
if (head == NULL)
    return NULL;

if (head->next == NULL)
    return head;
```

---

## Step 2: Find the Length of the List

Traverse the linked list to count the number of nodes.

At the same time, keep a pointer to the last node.

Example

```
1 → 2 → 3 → 4 → 5
```

After traversal

```
Length = 5

Last Node = 5
```

---

## Step 3: Reduce Unnecessary Rotations

Rotating a list of length `n` by `n` positions gives the same list.

Therefore,

```cpp
k = k % n;
```

Example

```
n = 5

k = 12
```

Effective rotations

```
12 % 5 = 2
```

If

```cpp
k == 0
```

return the original list.

---

## Step 4: Find the New Tail

The new tail is located at

```
n - k
```

from the beginning of the list.

Example

```
1 → 2 → 3 → 4 → 5

k = 2
```

New tail

```
3
```

New head

```
4
```

---

## Step 5: Rotate the List

Let

```
newHead = t->next;
```

Break the list.

```cpp
t->next = NULL;
```

Connect the last node to the original head.

```cpp
lastNode->next = firstNode;
```

Return

```cpp
newHead;
```

---

# Dry Run

### Input

```
1 → 2 → 3 → 4 → 5

k = 2
```

---

### Find Length

```
Length = 5

Last Node = 5
```

---

### Effective Rotations

```
k = 2 % 5

k = 2
```

---

### Find New Tail

```
Position = n - k = 3
```

```
1 → 2 → 3 → 4 → 5
        ↑
      New Tail
```

New head

```
4
```

---

### Rotate

Break

```
3 → NULL
```

Connect

```
5 → 1
```

Final list

```
4 → 5 → 1 → 2 → 3
```

---

# Why Use `k % n`?

Suppose

```
1 → 2 → 3 → 4 → 5
```

Length

```
n = 5
```

If

```
k = 10
```

Rotating 10 times is the same as rotating

```
10 % 5 = 0
```

times.

This avoids unnecessary work.

---

# Complexity Analysis

### Time Complexity

- One traversal to find the length.
- One traversal to find the new tail.

Overall

```
O(n)
```

---

### Space Complexity

Only a few pointers are used.

```
O(1)
```

---

# C++ Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return head;

        ListNode* firstNode = head;
        ListNode* temp = head;
        ListNode* t = head;

        int n = 1;

        while (temp->next != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
            return head;

        ListNode* lastNode = temp;

        int count = 1;
        int validIndex = n - k;

        while (count < validIndex) {
            t = t->next;
            count++;
        }

        ListNode* newHead = t->next;

        t->next = NULL;

        lastNode->next = firstNode;

        return newHead;
    }
};
```

---

# Key Takeaways

- Find the length of the linked list before rotating.
- Reduce unnecessary rotations using `k % n`.
- Locate the new tail at position `n - k`.
- The node after the new tail becomes the new head.
- Connect the original tail to the original head, then break the list at the new tail.
- This solution runs in **O(n)** time and uses **O(1)** extra space.
