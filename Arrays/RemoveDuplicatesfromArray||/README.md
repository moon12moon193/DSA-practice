# Remove Duplicates from Sorted Array II — LeetCode 80

## 📌 Problem Statement

You are given a sorted integer array `nums`.

Remove duplicates in-place such that:


each unique element appears at most twice


The relative order of elements must remain the same.

Return:


the length of the modified array


---

# 💡 Core Intuition

Because the array is already sorted:


duplicate values appear together


This allows us to control occurrences efficiently.

The goal is NOT:


remove all duplicates


The goal is:


allow duplicates only up to 2 times


---

# ⚙️ Approach Used

This solution uses:

* Two pointers
* In-place array modification
* Valid portion tracking

---

# 🧠 Key Insight

The first two elements are always valid because:


two occurrences are allowed


So traversal starts from index:


i = 2


---

# 📌 Pointer Meaning

## `i`

Traversal/read pointer.

Checks every element one-by-one.

---

## `j`

Write pointer.

Represents:


next valid insertion position


Also indicates size of valid portion.

---

# ✅ Important Observation

To decide whether current element should remain:

compare:


nums[i]


with:


nums[j-2]


Why?

Because:

* `j-2` represents second last element in valid array
* if both are same, current value would become third occurrence

---

# ✅ Cases

## Case 1 — Third Duplicate Found


nums[i] == nums[j-2]


This means:


adding current element would exceed allowed limit


So skip it.

---

# Case 2 — Valid Element


nums[i] != nums[j-2]


Current element is allowed.

Place it into valid portion:

nums[j] = nums[i]


Then:


j++


---

# 📌 Example

Input:

[1,1,1,2,2,3]


Process:


First two 1s allowed
Third 1 skipped
2 kept
Second 2 kept
3 kept


Final valid array:


[1,1,2,2,3]


Returned length:


5


---

# ⏱️ Time Complexity

Array traversed once.

# ✅

O(n)

---

# 💾 Space Complexity

No extra array used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Two-pointer technique
* In-place array modification
* Sorted array observations
* Duplicate control
* Read/write pointer pattern

---

# 🚨 Important Insight

Instead of explicitly counting occurrences:

compare current value with element two positions before in valid array


If same:

current value would become third duplicate


That elegant observation solves the problem efficiently.
