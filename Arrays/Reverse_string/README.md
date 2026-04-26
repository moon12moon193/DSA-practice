# 🔁 Reverse String (LeetCode #344)

## 🔹 Problem Statement

Write a function that reverses a string.

* The input is given as an array of characters `s`
* You must modify the array **in-place** with O(1) extra memory

---

## 🔹 Example

Input:


s =["h","e","l","l","o"]


Output:


["o","l","l","e","h"]


---

## 🔹 My Approach

* Use two pointers:

  * `i` starting from beginning
  * `j` starting from end
* Swap characters at `i` and `j`
* Move:

  * `i++` forward
  * `j--` backward

👉 Idea:

> Keep swapping elements from both ends until pointers meet

---


## 🔹 Key Concepts

* Two-pointer technique
* In-place swapping
* Array traversal

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity:O(1)

---

## 🔹 Important Notes ⚠️

* Swapping is done from both ends
* No extra memory is used
* Output is printed for visualization (not required by LeetCode)

---

## 🔹 Summary

* Use two pointers
* Swap elements from start and end
* Continue until pointers meet

👉 Simple and efficient way to reverse a string
