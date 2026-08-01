# Top K Frequent Elements (LeetCode 347)

## Problem

Given an integer array `nums` and an integer `k`, return the **k most frequent elements**.

You may return the answer in **any order**.

---

## Example 1

**Input**

```cpp
nums = [1,1,1,2,2,3]

k = 2
```

**Output**

```cpp
[1,2]
```

---

## Example 2

**Input**

```cpp
nums = [1]

k = 1
```

**Output**

```cpp
[1]
```

---

# Intuition

The problem has two parts:

1. Count the frequency of every element.
2. Find the `k` elements with the highest frequencies.

A **HashMap** efficiently stores the frequency of each element.

A **Min Heap** of size `k` keeps track of the `k` most frequent elements. The heap stores pairs in the form:

```text
(frequency, element)
```

The smallest frequency is always at the top of the heap. Whenever a more frequent element is found, it replaces the current minimum frequency in the heap.

---

# Approach

## Step 1: Count Frequencies

Use an `unordered_map` to count how many times each element appears.

```cpp
unordered_map<int, int> f;

for (int num : nums)
{
    f[num]++;
}
```

Example:

```text
nums = [1,1,1,2,2,3]
```

Frequency map:

```text
1 → 3
2 → 2
3 → 1
```

---

## Step 2: Create a Min Heap

Use a custom comparator to create a Min Heap based on frequency.

Each heap element stores:

```text
(frequency, value)
```

The comparator ensures:

- Smaller frequency has higher priority.
- If frequencies are equal, the smaller element comes first.

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    cmp
> pq;
```

---

## Step 3: Process Every Frequency

Traverse every entry in the HashMap.

### Case 1

If the heap contains fewer than `k` elements,

simply insert the current pair.

```cpp
pq.push({frequency, element});
```

---

### Case 2

If the heap already has `k` elements,

compare the current frequency with the smallest frequency stored in the heap.

If

```cpp
frequency > pq.top().first
```

then

- Remove the smallest frequency.
- Insert the new pair.

Otherwise,

ignore the current element.

---

## Step 4: Build the Answer

After processing all frequencies,

the heap contains exactly the `k` most frequent elements.

Pop each element and store only the value.

```cpp
while(!pq.empty())
{
    result.push_back(pq.top().second);
    pq.pop();
}
```

Return the result.

---

# Dry Run

### Input

```text
nums = [1,1,1,2,2,3]

k = 2
```

---

### Frequency Map

```text
1 → 3
2 → 2
3 → 1
```

---

### Process (3,1)

Heap:

```text
[(3,1)]
```

---

### Process (2,2)

Heap:

```text
[(2,2),(3,1)]
```

Heap size is now `2`.

---

### Process (1,3)

Current frequency:

```text
1
```

Heap top frequency:

```text
2
```

Since

```text
1 <= 2
```

Ignore it.

Heap remains

```text
[(2,2),(3,1)]
```

---

### Extract Answer

Pop heap:

```text
2
1
```

Result:

```text
[2,1]
```

Any order is accepted.

---

# Why Use a Min Heap?

Suppose

```text
k = 3
```

After processing several elements,

Heap:

```text
(4,A)
(7,B)
(9,C)
```

Top:

```text
(4,A)
```

Now another element has frequency

```text
8
```

Since

```text
8 > 4
```

remove

```text
(4,A)
```

and insert

```text
(8,D)
```

The heap always stores the **k highest frequencies**, while the smallest among them stays at the top for easy replacement.

---

# Complexity Analysis

### Time Complexity

Building the frequency map:

```text
O(n)
```

Processing the HashMap:

Each insertion/removal from the heap takes

```text
O(log k)
```

Overall:

```text
O(n + m log k)
```

where:

- `n` = size of the input array
- `m` = number of distinct elements

In the worst case:

```text
O(n log k)
```

---

### Space Complexity

HashMap:

```text
O(m)
```

Heap:

```text
O(k)
```

Overall:

```text
O(m + k)
```

---

# C++ Solution

```cpp
class Solution {
public:

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {

            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> result;

        unordered_map<int, int> f;

        for (int i = 0; i < nums.size(); i++) {
            f[nums[i]]++;
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            cmp
        > pq;

        for (auto elem : f) {

            int freq = elem.second;
            int element = elem.first;

            if (pq.size() < k) {

                pq.push({freq, element});

            } else {

                if (freq > pq.top().first) {

                    pq.pop();
                    pq.push({freq, element});
                }
            }
        }

        while (!pq.empty()) {

            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
```

---

# Key Takeaways

- Use a **HashMap** to count the frequency of each element.
- Store **(frequency, element)** pairs in a **Min Heap** of size `k`.
- The heap always maintains the `k` most frequent elements.
- When a higher frequency is found, replace the smallest frequency in the heap.
- This approach avoids sorting all frequencies and achieves an efficient **O(n + m log k)** solution.
- Combining **HashMap + Heap** is a common interview pattern for solving **Top K** problems.
