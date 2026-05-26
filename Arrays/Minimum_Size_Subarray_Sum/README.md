# Minimum Size Subarray Sum — LeetCode 209

## 📌 Problem Statement

Given an array of positive integers `nums` and a positive integer `target`.

Return:


the minimal length of a subarray


whose sum is:


greater than or equal to target


If there is no such subarray, return:


0


---

# 💡 Core Intuition

We need to:

* find contiguous subarrays
* calculate their sums
* track the minimum valid length

Instead of checking all possible subarrays using nested loops,
this solution uses:


Sliding Window Technique


which optimizes the traversal.

---

# ⚙️ Approach Used

This solution uses:

* Two pointers
* Sliding window
* Dynamic window expansion and shrinking

---

# 🧠 Sliding Window Idea

Maintain a window:


[i ... j]


where:

* `i` → left boundary
* `j` → right boundary

The window expands by moving:


j forward


and shrinks by moving:


i forward


when the current sum becomes large enough.

---

# ✅ Main Logic

## Step 1 — Expand Window

Add current element:


sum = sum + nums[j]


This increases the current window sum.

---

## Step 2 — Check Valid Window

While:


sum >= target


we found a valid subarray.

Calculate length:


len = j - i + 1


Update minimum answer:


ans = min(ans, len)


---

## Step 3 — Shrink Window

Remove left element:


sum = sum - nums[i]


Move left pointer:


i++


This tries to minimize the window length further.

---

# 📌 Example

Input:


target = 7
nums = [2,3,1,2,4,3]


---

# Step-by-Step Dry Run

## Window Expansion

| Window    | Sum | Valid? |
| --------- | --- | ------ |
| [2]       | 2   | ❌      |
| [2,3]     | 5   | ❌      |
| [2,3,1]   | 6   | ❌      |
| [2,3,1,2] | 8   | ✅      |

Length:


4


Shrink window:

| Window  | Sum |
| ------- | --- |
| [3,1,2] | 6   |

---

Continue expanding:

| Window    | Sum | Valid? |
| --------- | --- | ------ |
| [3,1,2,4] | 10  | ✅      |

Shrink repeatedly:

| Window  | Sum |
| ------- | --- |
| [1,2,4] | 7   |
| [2,4]   | 6   |

Minimum valid length becomes:


2


Subarray:


[4,3]


---

# ✅ Final Answer


2


---

# ⏱️ Time Complexity

Each element is:

* added once
* removed once

Therefore:


O(n)


---

# 💾 Space Complexity

No extra data structures used.


O(1)

---

# 🔑 Concepts Learned

* Sliding window technique
* Dynamic window resizing
* Two pointers
* Contiguous subarray processing
* Window shrinking optimization

---

# 🚨 Important Insight

Because all numbers are:


positive


increasing the window always increases sum,
and shrinking always decreases sum.

This property makes sliding window possible.

---


