# LeetCode - 1004. Max Consecutive Ones III

## Problem Statement

Given a binary array `nums` and an integer `k`, return the **maximum number of consecutive `1`s** in the array if you can flip at most `k` zeros.

---

# Intuition

We need to find the **longest contiguous subarray** that contains **at most `k` zeros**.

Instead of actually flipping the zeros, we simply allow our current window to contain at most `k` zeros.

If the number of zeros becomes greater than `k`, the window is no longer valid, so we shrink it from the left until it becomes valid again.

The maximum valid window length encountered during the traversal is the answer.

---

# Why Sliding Window?

The problem asks for:

* A **contiguous subarray**
* The **longest** valid window
* A condition that changes as the window expands (`number of zeros ≤ k`)

These are strong indicators that the **Sliding Window (Two Pointers)** technique should be used.

Since both pointers only move forward, every element is visited at most twice.

---

# Approach

Maintain two pointers:

* `low` → Left boundary of the window.
* `high` → Right boundary of the window.

Also maintain:

* Frequency of `0`s and `1`s inside the current window.
* Current window length.
* Number of zeros inside the current window.

For every new element:

1. Expand the window by moving `high`.
2. Update the frequency.
3. Calculate the number of zeros.
4. If zeros become greater than `k`, shrink the window by moving `low`.
5. Update the maximum window length.

---

# Counting Zeros

Instead of counting zeros separately while traversing, we use:


Window Length - Number of Ones = Number of Zeros


So,


zeroCount = length - countOfOnes


where


arr[1]


stores the frequency of `1`s in the current window.

---

# Algorithm

1. Initialize:


low = 0
high = 0
result = 0


2. Expand the window.

3. Update the frequency array.

4. Compute:


length = high - low + 1

zeroCount = length - onesCount


5. If:


zeroCount > k


shrink the window until it becomes valid.

6. Update the maximum window length.

7. Continue until `high` reaches the end of the array.

---

# Dry Run

Example:


nums = [1,1,1,0,0,0,1,1,1,1,0]

k = 2


Initially:


Window = []

low = 0

high = 0


As the window expands:


[1,1,1]


Zeros = 0

Valid.

Expand again:


[1,1,1,0,0]


Zeros = 2

Still valid.

Expand again:


[1,1,1,0,0,0]


Zeros = 3

Now:


3 > k


Shrink the window from the left until only two zeros remain.

Continue this process until the end of the array.

The largest valid window length obtained is the answer.

---


# Complexity Analysis

### Time Complexity


O(n)


Both pointers move only forward.

Each element enters and leaves the window at most once.

---

### Space Complexity


O(1)


Only a small frequency array of size `2` is used.

---

# Key Takeaways

* This is a classic **Sliding Window** problem.
* The window is always maintained so that it contains **at most `k` zeros**.
* The answer is simply the largest valid window.
* Number of zeros can be calculated as:

Window Length - Number of Ones


* Both pointers only move forward, resulting in an **O(n)** solution.
