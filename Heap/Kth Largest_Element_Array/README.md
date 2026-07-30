# Kth Largest Element in an Array (LeetCode 215)

## Problem

Given an integer array `nums` and an integer `k`, return the **kᵗʰ largest element** in the array.

Note:

- It is the **kᵗʰ largest element in the sorted order**, not the kᵗʰ distinct element.
- Your solution should work efficiently for large arrays.

---

## Example 1

**Input**

```cpp
nums = [3,2,1,5,6,4]
k = 2
```

**Output**

```cpp
5
```

---

## Example 2

**Input**

```cpp
nums = [3,2,3,1,2,4,5,5,6]
k = 4
```

**Output**

```cpp
4
```

---

# Intuition

Instead of sorting the entire array, we only need to keep track of the **k largest elements** seen so far.

A **Min Heap** of size `k` is perfect for this:

- The heap always stores the current **k largest elements**.
- The smallest element among those `k` elements is at the top.
- After processing all elements, the top of the heap is the **kᵗʰ largest element**.

---

# Approach

## Step 1: Create a Min Heap

Use a priority queue configured as a Min Heap.

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## Step 2: Insert the First `k` Elements

Push the first `k` elements into the heap.

```cpp
for(int i = 0; i < k; i++)
{
    pq.push(nums[i]);
}
```

Now the heap contains exactly `k` elements.

---

## Step 3: Process the Remaining Elements

Traverse the rest of the array.

For every element:

- If it is **smaller than or equal to** the heap's top, ignore it because it cannot belong to the largest `k` elements.
- Otherwise:
  - Remove the smallest element from the heap.
  - Insert the current element.

```cpp
if(nums[j] > pq.top())
{
    pq.pop();
    pq.push(nums[j]);
}
```

The heap size always remains `k`.

---

## Step 4: Return the Answer

After processing all elements,

the top of the Min Heap is the **kᵗʰ largest element**.

```cpp
return pq.top();
```

---

# Dry Run

### Input

```text
nums = [3,2,1,5,6,4]

k = 2
```

---

### Initial Heap

Insert first two elements.

```text
Heap

[2,3]
```

Top

```text
2
```

---

### Process 1

Current element

```text
1
```

Since

```text
1 <= 2
```

Ignore it.

Heap remains

```text
[2,3]
```

---

### Process 5

Current element

```text
5
```

Since

```text
5 > 2
```

Remove

```text
2
```

Insert

```text
5
```

Heap

```text
[3,5]
```

---

### Process 6

Current element

```text
6
```

Remove

```text
3
```

Insert

```text
6
```

Heap

```text
[5,6]
```

---

### Process 4

Current element

```text
4
```

Since

```text
4 <= 5
```

Ignore it.

Final Heap

```text
[5,6]
```

Top

```text
5
```

Answer

```text
5
```

---

# Why Does This Work?

The heap always contains the **largest `k` elements** encountered so far.

Whenever a larger element appears:

- The smallest element among the current top `k` is removed.
- The new larger element takes its place.

Therefore, after processing the entire array:

- The heap contains exactly the **k largest elements**.
- The smallest among them is precisely the **kᵗʰ largest element**.

---

# Complexity Analysis

### Time Complexity

Building the initial heap:

```text
O(k log k)
```

Processing the remaining elements:

```text
O((n - k) log k)
```

Overall:

```text
O(n log k)
```

---

### Space Complexity

The heap stores at most `k` elements.

```text
O(k)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert first k elements
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Process remaining elements
        for (int j = k; j < nums.size(); j++) {

            if (nums[j] <= pq.top()) {
                continue;
            }

            pq.pop();
            pq.push(nums[j]);
        }

        return pq.top();
    }
};
```

---

# Key Takeaways

- Use a **Min Heap** of size `k` to efficiently maintain the largest `k` elements.
- The heap's top always represents the smallest element among those `k` largest values.
- Ignore elements that are not larger than the heap's top.
- This approach avoids sorting the entire array and achieves **O(n log k)** time complexity.
- It is a common pattern used in **Top K**, **Kth Largest**, and **streaming data** problems.
