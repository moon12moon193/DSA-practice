# 🔀 Shuffle the Array (LeetCode #1470)

## 🔹 Problem Statement

You are given an array `nums` consisting of `2n` elements in the form:


[x1, x2, ..., xn, y1, y2, ..., yn]


Return the array in the form:


[x1, y1, x2, y2, ..., xn, yn]


---

## 🔹 Example

Input:

text
nums = [2,5,1,3,4,7], n = 3


Output:


[2,3,5,4,1,7]


---

## 🔹 My Approach

* Create a new array `result` of same size

* Use two pointers:

  * `i` → for first half (0 to n-1)
  * `j` → for second half (n to 2n-1)

* Traverse both halves together:

  * Place `nums[i]` at index `2*i`
  * Place `nums[j]` at index `2*i + 1`

👉 Idea:

> For each position `i`, place both corresponding elements (`x` and `y`) together

---


## 🔹 Key Concepts

* Array indexing
* Two-pointer technique
* Mapping indices to new positions

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(n)

---

## 🔹 Edge Cases

* Minimum size array
* All elements same
* Large values

---

## 🔹 Summary

* Split array logically into two halves
* Place elements alternately in result array
* Maintain correct index mapping

👉 Simple and efficient approach using two pointers
