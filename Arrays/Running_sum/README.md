# 🔄 Running Sum of 1D Array (LeetCode #1480)

## 🔹 Problem Statement

Given an array `nums`, return the **running sum** of the array.

The running sum at index `i` is defined as:

* sum of all elements from index `0` to `i`

---

## 🔹 Example

Input:


nums = [1,2,3,4]


Output:


[1,3,6,10]


Explanation:

* Index 0 → 1
* Index 1 → 1 + 2 = 3
* Index 2 → 1 + 2 + 3 = 6
* Index 3 → 1 + 2 + 3 + 4 = 10

---

## 🔹 My Approach

* Start from the second element (index 1)
* Keep a variable that stores the cumulative sum
* At each step:

  * Add current element to the running sum
  * Update the array with the new sum

👉 Idea:

> Keep adding previous values to build cumulative total

---

## 🔹 Key Concepts

* Prefix sum (running sum)
* Array traversal
* In-place modification

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---

## 🔹 Edge Cases

* Single element array → remains same
* Empty array (if considered)

---

## 🔹 Summary

* Traverse the array once
* Keep updating cumulative sum
* Store result in same array

👉 Simple and efficient use of prefix sum technique
