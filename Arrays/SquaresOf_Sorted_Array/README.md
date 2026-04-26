# 🔢 Squares of a Sorted Array (LeetCode #977)

## 🔹 Problem Statement

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number, also sorted in non-decreasing order.

---

## 🔹 Example

Input:


nums = [-4,-1,0,3,10]

Output:


[0,1,9,16,100]


Explanation:

* Squares: [16,1,0,9,100]
* After sorting: [0,1,9,16,100]

---

## 🔹 My Approach

* Traverse the array and square each element
* After squaring, the array may become unsorted
* Apply sorting to arrange elements in increasing order

👉 Idea:

> First transform values, then sort to restore order

---



## 🔹 Key Concepts

* Array traversal
* Element transformation (squaring)
* Sorting

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n log n) (due to sorting)
* Space Complexity: O(1) (in-place modification, ignoring output)

---

## 🔹 Edge Cases

* All negative numbers
* All positive numbers
* Includes zero

---

## 🔹 Summary

* Square each element
* Sort the array
* Return the result

👉 Simple and straightforward solution using sorting
