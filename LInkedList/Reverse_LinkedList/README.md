# Reverse Linked List (LeetCode 206)

## Problem

Given the `head` of a singly linked list, reverse the linked list and return the new head.

---

## Example 1

**Input**


head = [1,2,3,4,5]


**Output**


[5,4,3,2,1]


---

## Example 2

**Input**


head = [1,2]


**Output**


[2,1]


---

## Example 3

**Input**


head = []


**Output**


[]


---

# Intuition

A singly linked list only allows us to move in one direction.


1 → 2 → 3 → 4 → 5 → NULL


To reverse the list, we must change the direction of every `next` pointer.

5 → 4 → 3 → 2 → 1 → NULL


While changing a pointer, we must be careful not to lose the remaining part of the list.

To do this, we use three pointers:

- `prev` → Points to the previous node.
- `curr` → Points to the current node.
- `next` → Temporarily stores the next node before changing the link.

---

# Approach

## Step 1: Initialize Pointers


prev = NULL;
curr = head;


Initially,

- `prev` points to nothing.
- `curr` points to the first node.

---

## Step 2: Save the Next Node

Before changing any pointer, save the next node.


ListNode* next = curr->next;


This prevents losing the remaining linked list.

---

## Step 3: Reverse the Link

Make the current node point to the previous node.


curr->next = prev;


Example

Before


NULL    1 → 2 → 3
        ↑
      curr


After


NULL ← 1    2 → 3
        ↑
      curr


The link is now reversed.

---

## Step 4: Move Both Pointers Forward

Move `prev` to the current node.

prev = curr;


Move `curr` to the saved next node.


curr = next;


Repeat the same process until `curr` becomes `NULL`.

---

## Step 5: Return the New Head

When the loop finishes,

curr = NULL


and


prev


points to the new head of the reversed linked list.

Return


prev


---

# Dry Run

### Input


1 → 2 → 3 → NULL


---

### Initially

prev = NULL

curr = 1


---

### Iteration 1

Save next node.


next = 2


Reverse the link.


1 → NULL


Move pointers.


prev = 1

curr = 2


---

### Iteration 2

Save next node.


next = 3


Reverse the link.


2 → 1 → NULL


Move pointers.

prev = 2

curr = 3


---

### Iteration 3

Save next node.

next = NULL


Reverse the link.

3 → 2 → 1 → NULL


Move pointers.

prev = 3

curr = NULL


Loop ends.

Return


3


which is the new head.

---

# Why Do We Need the `next` Pointer?

Suppose we directly reverse the pointer.


curr->next = prev;


Without saving


curr->next


first,

the remaining linked list is lost.

Example

Before


1 → 2 → 3


After


1 → NULL


Now there is no way to reach nodes `2` and `3`.

Saving


next = curr->next;


keeps a reference to the remaining list.

---

# Complexity Analysis

### Time Complexity

Each node is visited exactly once.


O(n)


---

### Space Complexity

Only three pointers are used.


O(1)




---

# Key Takeaways

- Use three pointers: **`prev`**, **`curr`**, and **`next`**.
- Always save the next node before changing any links.
- Reverse each node's `next` pointer one by one.
- Move the pointers forward after each reversal.
- When the loop finishes, `prev` points to the new head of the reversed linked list.
- This iterative solution runs in **O(n)** time and uses **O(1)** extra space.
