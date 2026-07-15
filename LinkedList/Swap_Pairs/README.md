# Swap Nodes in Pairs (LeetCode 24)

## Problem

Given the head of a singly linked list, swap every two adjacent nodes and return the new head.

You **must not modify the values** inside the nodes. Only the node connections (pointers) may be changed.

---

## Example 1

**Input**

```cpp
head = [1,2,3,4]
```

**Output**

```cpp
[2,1,4,3]
```

---

## Example 2

**Input**

```cpp
head = []
```

**Output**

```cpp
[]
```

---

## Example 3

**Input**

```cpp
head = [1]
```

**Output**

```cpp
[1]
```

---

# Intuition

Instead of swapping the values of the nodes, we swap the **links between the nodes**.

For every pair:

```
1 → 2
```

we want to transform it into

```
2 → 1
```

The linked list is processed **two nodes at a time**.

For each pair, we:

1. Check whether two nodes are available.
2. Reverse those two nodes.
3. Connect the reversed pair with the previous part of the list.
4. Move to the next pair.

---

# Approach

## Step 1: Process Two Nodes at a Time

Let

```
left
```

point to the first node of the current pair.

Find the second node using

```
right
```

If two nodes are not available, leave the remaining nodes unchanged.

---

## Step 2: Save the Next Pair

Before reversing the current pair, save the starting node of the next pair.

```cpp
nextLeft = right->next;
```

This is necessary because reversing changes the `next` pointers.

---

## Step 3: Reverse the Current Pair

Reverse exactly **2 nodes**.

Example

Before

```
1 → 2
```

After

```
2 → 1
```

---

## Step 4: Connect with the Previous Pair

If this is not the first pair,

```
previousPairTail → newHeadOfCurrentPair
```

Example

Before

```
2 → 1

3 → 4
```

After reversing the second pair

```
4 → 3
```

Connect

```
2 → 1 → 4 → 3
```

---

## Step 5: Move to the Next Pair

The original first node becomes the tail after reversal.

Move

```
left
```

to the next pair.

Repeat until fewer than two nodes remain.

---

# Dry Run

### Input

```
1 → 2 → 3 → 4
```

---

### First Pair

Current pair

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

Current list

```
2 → 1
```

---

### Second Pair

Current pair

```
3 → 4
```

Save

```
nextLeft = NULL
```

Reverse

```
4 → 3
```

Connect with previous pair

```
2 → 1 → 4 → 3
```

Loop ends.

Final answer

```
2 → 1 → 4 → 3
```

---

# Why Save `nextLeft` Before Reversing?

Suppose

```
1 → 2 → 3 → 4
```

If we reverse first,

```
2 → 1
```

then

```
right->next
```

no longer points to `3`.

Instead,

```
right->next
```

points back to `1`.

Therefore, the starting node of the next pair must be saved **before** reversing.

```cpp
nextLeft = right->next;
```

---

# Complexity Analysis

### Time Complexity

Each node is visited only once.

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

    ListNode* swapPairs(ListNode* head) {

        ListNode* left = head;
        ListNode* prevNode = NULL;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* nextLeft;

        int k = 2;

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

- Process the linked list **two nodes at a time**.
- Save the next pair before reversing the current pair.
- Reverse only the current pair using pointer manipulation.
- Reconnect the previous pair with the newly reversed pair.
- Leave the last node unchanged if the list contains an odd number of nodes.
- The algorithm runs in **O(n)** time and uses **O(1)** extra space.


