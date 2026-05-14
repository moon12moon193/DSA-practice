# Sort Colors — LeetCode 75

## 📌 Problem Statement

You are given an array containing only:


0, 1, and 2


where:

* `0` represents red
* `1` represents white
* `2` represents blue

Sort the array in-place so that:

* all `0`s come first
* then all `1`s
* then all `2`s

---

# 💡 Core Idea

Instead of using normal sorting:


place each number directly into its correct region


This solution uses the famous:

# 🇳🇱 Dutch National Flag Algorithm

The array is divided into 3 sections:

* left side → all `0`s
* middle → all `1`s
* right side → all `2`s

---

# ⚙️ Pointers Used

Three pointers are maintained:
low
mid
high


---

# 📌 Meaning of Each Pointer

## `low`

Tracks position where next `0` should go.

---

## `mid`

Current element being processed.

---

## `high`

Tracks position where next `2` should go.

---

# 🧠 Array Structure During Traversal

At any moment:


0 → low-1        = all 0s
low → mid-1      = all 1s
mid → high       = unknown region
high+1 → end     = all 2s


---

# ✅ Algorithm Steps

## Case 1 — Current element is `0`


swap(nums[mid], nums[low]);


Why?

0 belongs to left side


Then:


low++
mid++


because both regions expand correctly.

---

# Case 2 — Current element is `1`

`1` already belongs in middle section.

So simply:


mid++


---

# Case 3 — Current element is `2`


swap(nums[mid], nums[high]);


Why?


2 belongs to right side


Then:


high--


Important:

mid is NOT incremented here


because swapped value from right side is still unchecked.

---

# 📌 Example

Input:

[2,0,2,1,1,0]


Traversal gradually transforms array into:

[0,0,1,1,2,2]


---

# ⏱️ Time Complexity

Array is traversed once.

# ✅

O(n)

---

# 💾 Space Complexity

No extra array used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Dutch National Flag Algorithm
* Three-pointer technique
* In-place sorting
* Partitioning arrays
* Optimized linear traversal

---

# 🚨 Important Insight

When `2` is swapped from right side:


do not move mid immediately


because new value at `mid` still needs processing.

This is the key detail of the algorithm.
