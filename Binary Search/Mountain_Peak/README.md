# Peak Index in a Mountain Array (LeetCode 852)

## Problem

A **mountain array** is an array where:

- The elements strictly increase to a peak.
- After the peak, the elements strictly decrease.

Given a mountain array `arr`, return the **index of the peak element**.

You must solve the problem in **O(log n)** time.

---

## Example 1

**Input**

```cpp
arr = [0,1,0]
```

**Output**

```cpp
1
```

### Explanation

The value `1` is greater than both its neighbors, so its index `1` is the peak.

---

## Example 2

**Input**

```cpp
arr = [0,2,1,0]
```

**Output**

```cpp
1
```

### Explanation

The element `2` is the highest value in the mountain array.

---

## Example 3

**Input**

```cpp
arr = [0,10,5,2]
```

**Output**

```cpp
1
```

---

# Intuition

A mountain array has two distinct parts:

- **Increasing slope**
- **Decreasing slope**

The peak lies exactly where the increasing slope changes into the decreasing slope.

Using Binary Search:

- If we are on the **increasing slope**, move right.
- If we are on the **decreasing slope**, move left.
- If the current element is greater than both neighbors, it is the peak.

This allows us to eliminate half of the search space in every iteration.

---

# Approach

## Step 1: Initialize the Search Range

The first and last elements **cannot** be the peak in a valid mountain array.

Therefore,

```cpp
low = 1;
high = arr.size() - 2;
```

---

## Step 2: Find the Middle Element

Calculate the middle index safely.

```cpp
int mid = low + (high - low) / 2;
```

---

## Step 3: Check Whether `mid` is the Peak

If

```cpp
arr[mid] > arr[mid - 1]
```

and

```cpp
arr[mid] > arr[mid + 1]
```

then

```cpp
return mid;
```

---

## Step 4: Decide the Search Direction

### Case 1: Increasing Slope

If

```cpp
arr[mid] < arr[mid + 1]
```

the peak must be on the right.

```cpp
low = mid + 1;
```

---

### Case 2: Decreasing Slope

If

```cpp
arr[mid] > arr[mid + 1]
```

and it is not already the peak,

the peak must lie on the left.

```cpp
high = mid - 1;
```

---

## Step 5: Return the Result

Once the peak is found,

return its index.

---

# Dry Run

### Input

```text
arr = [0,2,5,3,1]
```

---

### Iteration 1

```text
low = 1
high = 3

mid = 2

arr[mid] = 5
```

Check neighbors:

```text
5 > 2 ✔
5 > 3 ✔
```

Peak found.

Return

```text
2
```

---

# Another Example

### Input

```text
arr = [0,1,2,4,3,2]
```

---

### Iteration 1

```text
low = 1
high = 4

mid = 2

arr[mid] = 2
arr[mid + 1] = 4
```

Since

```text
2 < 4
```

we are on the increasing slope.

Move right.

```text
low = 3
```

---

### Iteration 2

```text
low = 3
high = 4

mid = 3

arr[mid] = 4
```

Check neighbors:

```text
4 > 2 ✔
4 > 3 ✔
```

Peak found.

Return

```text
3
```

---

# Why Start from Index 1 and End at `n - 2`?

A peak element must have **both a left and a right neighbor**.

The first element has no left neighbor.

The last element has no right neighbor.

Therefore,

```cpp
low = 1;
high = n - 2;
```

ensures that accessing

```cpp
arr[mid - 1]
```

and

```cpp
arr[mid + 1]
```

is always safe.

---

# Complexity Analysis

### Time Complexity

Each iteration eliminates half of the search space.

```text
O(log n)
```

where `n` is the size of the array.

---

### Space Complexity

Only a few variables are used.

```text
O(1)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int low = 1;
        int high = arr.size() - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1] &&
                arr[mid] > arr[mid - 1]) {

                return mid;
            }
            else if (arr[mid] < arr[mid + 1]) {

                low = mid + 1;
            }
            else if (arr[mid] > arr[mid + 1]) {

                high = mid - 1;
            }
        }

        return -1;
    }
};
```

---

# Key Takeaways

- A mountain array consists of an **increasing** part followed by a **decreasing** part.
- Use Binary Search to determine whether the middle element lies on the increasing slope, decreasing slope, or is the peak.
- Restrict the search range to `1` through `n - 2` because the first and last elements cannot be peaks in a valid mountain array.
- The algorithm finds the peak in **O(log n)** time using **O(1)** extra space.
