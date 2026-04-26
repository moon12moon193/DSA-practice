# 🗑️ Remove Element (LeetCode #27)

## 🔹 Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place.

Return the number of elements `k` that are **not equal to `val`**.

* The first `k` elements of `nums` should contain elements ≠ `val`
* Remaining elements can be ignored

---

## 🔹 Example

Input:

nums = [3,2,2,3], val = 3


Output:

k = 2
nums = [2,2,_,_]


---

## 🔹 My Approach

* Traverse the array from start to end
* Maintain a pointer `k` to track position of valid elements
* If current element is not equal to `val`:

  * Place it at index `k`
  * Increment `k`

👉 Idea:

> Keep only the elements that are not equal to `val` at the beginning of the array

---


## 🔹 Key Concepts

* In-place modification
* Array traversal
* Overwriting unwanted elements

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---

## 🔹 Edge Cases

* All elements equal to `val` → return 0
* No element equal to `val` → return size of array

---

## 🔹 Summary

* Traverse array once
* Copy valid elements forward
* Return count of valid elements


