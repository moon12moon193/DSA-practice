# Majority Element — LeetCode 169

## 📌 Problem Statement

Given an integer array `nums`, find the:

majority element


A majority element is the element that appears:



times in the array.

The problem guarantees that a majority element always exists.

---

# 💡 Core Intuition

If the array is sorted:


same values become adjacent


Then counting occurrences becomes easy.

The element whose count becomes greater than:

n/2

is the majority element.

---

# ⚙️ Approach Used

This solution uses:

* Sorting
* Consecutive occurrence counting

---

# 🧠 Why Sorting Helps

Example:

Input:


[2,2,1,1,1,2,2]


After sorting:


[1,1,1,2,2,2,2]


Now duplicate values appear together,
making counting simple.

---

# ✅ Algorithm Steps

## 1. Handle Single Element Case

If array size is:


1


then that element is automatically majority element.

---

# 2. Sort the Array


sort(nums.begin(), nums.end());


---

# 3. Traverse and Count Consecutive Occurrences

Initialize:


count = 1


Then compare current element with previous element.

---

## If Same


count++


because occurrence continues.

---

## If Different


count = 1


because a new number starts.

---

# 4. Check Majority Condition

If:

{count} > \n/2

then current element is majority element.

Return it immediately.

---

# 📌 Example

Input:

[3,2,3]


Sorted:


[2,3,3]


Traversal:

* `2` → count = 1
* `3` → new number → count = 1
* `3` again → count = 2

Since:

2 > 3/2

majority element becomes:

3


---

# ⏱️ Time Complexity

## Sorting

O(n\log n)

---

## Traversal

O(n)

---

# ✅ Overall Time Complexity

Dominated by sorting:

O(n\log n)

---

# 💾 Space Complexity

No extra data structures used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Sorting for grouping duplicates
* Frequency counting
* Majority element definition
* Consecutive traversal logic

---

# 🚨 Important Insight

After sorting:


majority element must appear consecutively


So counting adjacent duplicates is enough to find the answer.
