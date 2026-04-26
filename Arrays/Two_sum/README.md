# 🔍 Two Sum (LeetCode #1)

## 🔹 Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

* You may assume that each input has exactly one solution
* You cannot use the same element twice

---

## 🔹 Example

**Input:**


nums = [2,7,11,15], target = 9


Output:


[0,1]


Explanation:

* nums[0] + nums[1] = 2 + 7 = 9

---

## 🔹 My Approach (Brute Force)

* Use two nested loops:

  * First loop selects an element
  * Second loop checks all elements after it
* If the sum equals target:

  * Store indices in result vector
  * Break inner loop

👉 Idea:

> Check every possible pair to find the correct sum

---


## 🔹 Key Concepts

* Array traversal
* Nested loops
* Pair comparison

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n²)
* Space Complexity: O(1) (excluding output array)

---

## 🔹 Edge Cases

* Only one valid pair exists (as per problem)
* Array size ≥ 2

---

## 🔹 Summary

* Try all pairs using two loops
* Find pair whose sum equals target
* Return their indices

👉 Simple and beginner-friendly brute force approach
