# Linked List Cycle (LeetCode 141)

## Problem

Given the `head` of a singly linked list, determine whether the linked list contains a cycle.

A cycle exists if some node in the list can be reached again by continuously following the `next` pointer.

Return:

- `true` if there is a cycle.
- `false` otherwise.

---

## Example 1

**Input**


head = [3,2,0,-4]
pos = 1


**Output**


true


### Explanation

The last node points back to the node with value `2`, creating a cycle.

---

## Example 2

**Input**


head = [1,2]
pos = 0


**Output**


true


---

## Example 3

**Input**


head = [1]
pos = -1


**Output**

false


There is no cycle in the linked list.

---

# Intuition

A brute-force approach would be to store every visited node in a hash set.

If we visit the same node again, a cycle exists.

However, this requires **O(n)** extra space.

A better approach is **Floyd's Cycle Detection Algorithm (Tortoise and Hare Algorithm)**, which uses two pointers moving at different speeds.

- **Slow Pointer** → moves one step at a time.
- **Fast Pointer** → moves two steps at a time.

If a cycle exists, the fast pointer will eventually catch up with the slow pointer.

If there is no cycle, the fast pointer will reach the end of the list.

---

# Approach

## Step 1: Initialize Two Pointers

Both pointers start from the head.


ListNode* slow = head;
ListNode* fast = head;


---

## Step 2: Traverse the Linked List

Continue while the fast pointer can move.


while (fast != NULL && fast->next != NULL)

Inside the loop:


slow = slow->next;


Move the slow pointer one step.


fast = fast->next->next;


Move the fast pointer two steps.

---

## Step 3: Check for a Cycle

If both pointers point to the same node,


if (slow == fast)


then a cycle exists.

Return


true;


---

## Step 4: No Cycle Found

If the loop ends because the fast pointer reaches `NULL`, the list has no cycle.

Return


false;


---

# Why Does This Work?

Imagine a circular running track.

- One runner walks **1 step** at a time.
- Another runner runs **2 steps** at a time.

Since the faster runner gains **1 step** on the slower runner during each move, they will eventually meet if they keep running on the same circular track.

The linked list cycle works in exactly the same way.

If there is no cycle, the faster runner simply reaches the end of the list.

---

# Dry Run

### Input


3 → 2 → 0 → -4
    ↑         |
    |_________|


---

### Initially


Slow = 3

Fast = 3


---

### Iteration 1

Slow moves one step.


2


Fast moves two steps.


0


Pointers are different.

---

### Iteration 2

Slow


0


Fast


2


Pointers are different.

---

### Iteration 3

Slow


-4


Fast


-4


Both pointers meet.

Return


true


---

# Why Doesn't the Fast Pointer Skip the Slow Pointer?

The fast pointer moves two nodes while the slow pointer moves one.

Inside the cycle:

- Slow gains **1 node** each iteration.
- Fast gains **2 nodes** each iteration.

Therefore, the distance between them decreases by **1 node** every iteration (modulo the cycle length).

Eventually, the distance becomes zero, and both pointers point to the same node.

---

# Complexity Analysis

### Time Complexity

Each pointer visits at most `n` nodes.


O(n)


---

### Space Complexity

Only two pointers are used.


O(1)


---


# Key Takeaways

- Use **Floyd's Cycle Detection Algorithm (Tortoise and Hare)** to detect a cycle efficiently.
- The **slow pointer** moves one step, while the **fast pointer** moves two steps.
- If a cycle exists, the two pointers will eventually meet.
- If the fast pointer reaches `NULL`, the linked list does not contain a cycle.
- This approach is optimal with **O(n)** time and **O(1)** extra space.
