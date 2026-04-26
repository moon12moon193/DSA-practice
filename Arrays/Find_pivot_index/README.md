# ⚖️ Find Pivot Index (LeetCode #724)

## 🔹 Problem Statement

Given an integer array `nums`, find the pivot index.

The pivot index is the index where:

* The sum of elements to the left is equal to
* The sum of elements to the right

Return the leftmost pivot index.
If no such index exists, return `-1`.

---

## 🔹 Example

Input:


nums = [1,7,3,6,5,6]


Output:

3


Explanation:

* Left sum = 1 + 7 + 3 = 11
* Right sum = 5 + 6 = 11
  👉 Both are equal at index 3

---

## 🔹 My Approach

* Create two arrays:

  * `Leftarray` → stores sum of elements to the left of each index
  * `Rightarray` → stores sum of elements to the right of each index

* Traverse the array:

  * Build left prefix sums
  * Build right suffix sums

* Compare both arrays:

  * If `Leftarray[k] == Rightarray[k]`, return index `k`

👉 Idea:

> Precompute left and right sums, then find where they match

---



## 🔹 Key Concepts

* Prefix sum (left side)
* Suffix sum (right side)
* Array traversal

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(n) (extra arrays used)

---

## 🔹 Edge Cases

* Pivot at index 0 (left sum = 0)
* Pivot at last index (right sum = 0)
* No pivot → return -1

---

## 🔹 Summary

* Compute left and right sums for each index
* Compare both sums
* Return the first matching index


