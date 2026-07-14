# Reverse Linked List II (LeetCode 92)

## Problem

Given the head of a singly linked list and two integers `left` and `right`, reverse the nodes of the list from position `left` to position `right`, and return the modified list.

The positions are **1-indexed**.

---

## Example 1

**Input**

```cpp
head = [1,2,3,4,5]
left = 2
right = 4
```

**Output**

```cpp
[1,4,3,2,5]
```

### Explanation

Reverse only the nodes from position `2` to `4`.

Before

```
1 → 2 → 3 → 4 → 5
```

After

```
1 → 4 → 3 → 2 → 5
```

---

## Example 2

**Input**

```cpp
head = [5]
left = 1
right = 1
```

**Output**

```cpp
[5]
```

---

# Intuition

Instead of reversing the entire linked list, we only reverse a specific portion.

To do this, we divide the list into **three parts**.

```
Before Reversal

1 → 2 → 3 → 4 → 5 → 6

left = 2
right = 5
```

```
Part 1        Part 2           Part 3

1      |    2 → 3 → 4 → 5    |    6
```

Our goal is:

1. Remember the node before the reversal starts.
2. Reverse only the middle part.
3. Connect all three parts back together.

---

# Approach

## Step 1: Handle the Edge Case

If

```cpp
left == right
```

there is nothing to reverse.

Return the original list.

---

## Step 2: Reach the Left Position

Use a pointer `t` to reach the node at position `left`.

At the same time, store the node before it.

```cpp
before
```

Example

```
1 → 2 → 3 → 4 → 5

left = 3
```

After traversal

```
before

↓

1 → 2 → 3 → 4 → 5
      ↑
      t
```

- `before` points to node `2`.
- `t` points to node `3`.

---

## Step 3: Reverse the Required Nodes

Reverse exactly

```cpp
right - left + 1
```

nodes.

Use the standard three-pointer technique.

```cpp
prev
curr
next
```

During reversal

```
3 → 4 → 5
```

becomes

```
5 → 4 → 3
```

At the end,

- `prev` points to the first node of the reversed section.
- `curr` points to the node immediately after the reversed section.

---

## Step 4: Connect the Tail

The original first node of the reversed section (`t`) becomes the last node after reversal.

Connect it to the remaining list.

```cpp
t->next = curr;
```

Example

```
5 → 4 → 3

curr

↓

6
```

Result

```
5 → 4 → 3 → 6
```

---

## Step 5: Connect the Front

If the reversal does not start from the head,

```
before
```

should point to the new first node of the reversed section.

```cpp
before->next = prev;
```

Otherwise,

if

```cpp
left == 1
```

the new head becomes

```cpp
prev
```

---

# Dry Run

### Input

```
1 → 2 → 3 → 4 → 5

left = 2

right = 4
```

---

### Initial

```
before = 1

t = 2
```

---

### Reverse

```
2 → 3 → 4
```

becomes

```
4 → 3 → 2
```

Now

```
prev

↓

4 → 3 → 2

curr

↓

5
```

---

### Connect Tail

```
2 → 5
```

---

### Connect Front

```
1 → 4
```

Final list

```
1 → 4 → 3 → 2 → 5
```

---

# Why Do We Need `before`?

Suppose

```
1 → 2 → 3 → 4 → 5

left = 3
```

After reversing

```
4 → 3
```

Without storing

```
before
```

there is no way to reconnect

```
2
```

to

```
4
```

Therefore,

```cpp
before->next = prev;
```

is necessary.

---

# Why Do We Need `t`?

Initially,

```
t
```

points to the first node of the part being reversed.

After reversal,

it becomes the **last node**.

We use

```cpp
t->next = curr;
```

to connect the reversed section with the remaining list.

---

# Complexity Analysis

### Time Complexity

The linked list is traversed only once.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) {
            return head;
        }

        ListNode* before = NULL;
        ListNode* t = head;

        int position = 1;

        while (position < left) {
            before = t;
            t = t->next;
            position++;
        }

        int times = right - left + 1;

        ListNode* prev = NULL;
        ListNode* curr = t;

        while (times--) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        t->next = curr;

        if (before != NULL) {

            before->next = prev;
            return head;
        }

        return prev;
    }
};
```

---

# Key Takeaways

- Divide the list into **three parts**:
  1. Nodes before the reversal.
  2. Nodes to reverse.
  3. Nodes after the reversal.
- Reverse only `right - left + 1` nodes using the standard linked list reversal technique.
- `before` stores the node before the reversed section.
- `t` becomes the tail of the reversed section after reversal.
- Reconnect both ends of the reversed section to form the final linked list.
- The algorithm runs in **O(n)** time with **O(1)** extra space.
