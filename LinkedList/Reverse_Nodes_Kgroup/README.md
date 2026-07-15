# Reverse Nodes in k-Group (LeetCode 25)

## Problem

Given the head of a linked list, reverse the nodes of the list **k at a time** and return the modified list.

- If the number of remaining nodes is less than `k`, leave them as they are.
- You may **not** change the values inside the nodes; only the node connections (pointers) may be changed.

---

## Example 1

**Input**

```cpp
head = [1,2,3,4,5]
k = 2
```

**Output**

```cpp
[2,1,4,3,5]
```

---

## Example 2

**Input**

```cpp
head = [1,2,3,4,5]
k = 3
```

**Output**

```cpp
[3,2,1,4,5]
```

---

## Example 3

**Input**

```cpp
head = [1,2]
k = 3
```

**Output**

```cpp
[1,2]
```

Since fewer than `k` nodes remain, they are not reversed.

---

# Intuition

Instead of reversing the entire linked list, we reverse only **groups of `k` consecutive nodes**.

For each group:

1. Check whether there are at least `k` nodes.
2. If yes, reverse the group.
3. Connect it with the previously reversed group.
4. Move to the next group.
5. If fewer than `k` nodes remain, stop and leave them unchanged.

---

# Approach

## Step 1: Locate a Group of `k` Nodes

Use two pointers:

- `left` → points to the first node of the current group.
- `right` → moves forward to find the last node of the current group.

Example (`k = 3`)

```
1 → 2 → 3 → 4 → 5 → 6

left             right
```

If `right` becomes `NULL` before completing `k` nodes, the remaining nodes are left unchanged.

---

## Step 2: Save the Next Group

Before reversing the current group, save the starting node of the next group.

```cpp
nextLeft = right->next;
```

This is necessary because reversing changes the `next` pointers.

---

## Step 3: Reverse the Current Group

Reverse exactly `k` nodes using the standard linked list reversal technique.

Before

```
1 → 2 → 3
```

After

```
3 → 2 → 1
```

---

## Step 4: Connect the Previous Group

If this is not the first group,

```
previous group's tail
        │
        ▼
3 → 2 → 1
```

Connect

```cpp
prevNode->next = right;
```

where `right` becomes the new head of the reversed group.

---

## Step 5: Prepare for the Next Group

After reversing,

- The original first node (`left`) becomes the tail.
- Update

```cpp
prevNode = left;
```

Move

```cpp
left = nextLeft;
```

Repeat the same process for the next group.

---

## Step 6: Handle Remaining Nodes

If fewer than `k` nodes remain,

```
... → remaining nodes
```

connect them directly without reversing.

```cpp
prevNode->next = left;
```

The algorithm then terminates.

---

# Dry Run

### Input

```
1 → 2 → 3 → 4 → 5

k = 2
```

---

### First Group

Current group

```
1 → 2
```

Save

```
nextLeft = 3
```

Reverse

```
2 → 1
```

Result

```
2 → 1
```

---

### Second Group

Current group

```
3 → 4
```

Save

```
nextLeft = 5
```

Reverse

```
4 → 3
```

Connect

```
2 → 1 → 4 → 3
```

---

### Remaining Nodes

Only

```
5
```

is left.

Since there are fewer than `k` nodes, leave it unchanged.

Final answer

```
2 → 1 → 4 → 3 → 5
```

---

# Why Save `nextLeft` Before Reversing?

Suppose

```
1 → 2 → 3 → 4
```

After reversing the first group,

```
2 → 1
```

the `next` pointers have changed.

If we try

```cpp
right->next
```

after reversal, it no longer points to node `3`.

Therefore,

```cpp
nextLeft = right->next;
```

must be saved **before** reversing the group.

---

# Complexity Analysis

### Time Complexity

Each node is visited only once.

```
O(n)
```

where `n` is the number of nodes in the linked list.

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

    void reverse(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* prev = NULL;

        int number = 1;

        while (number <= k) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;

            number++;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* left = head;
        ListNode* prevNode = NULL;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* nextLeft;

        while (true) {

            right = left;

            for (int i = 0; i < k - 1; i++) {

                if (right != NULL)
                    right = right->next;
            }

            if (right != NULL) {

                nextLeft = right->next;

                reverse(left, k);

                if (prevNode != NULL)
                    prevNode->next = right;

                prevNode = left;

                left = nextLeft;

                if (res == NULL)
                    res = right;

            } else {

                if (prevNode != NULL)
                    prevNode->next = left;

                if (res == NULL)
                    res = left;

                break;
            }
        }

        return res;
    }
};
```

---

# Key Takeaways

- Reverse the linked list **one group of `k` nodes at a time**.
- Before reversing, verify that a complete group of `k` nodes exists.
- Save the starting node of the next group before changing any links.
- Connect each reversed group with the previous one.
- Leave the remaining nodes unchanged if their count is less than `k`.
- This approach processes each node only once, achieving **O(n)** time complexity with **O(1)** extra space.

