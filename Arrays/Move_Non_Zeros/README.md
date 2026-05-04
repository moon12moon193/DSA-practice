# 🚚 Move Zeroes (LeetCode #283)

## 🔹 Problem Statement

Given an integer array `nums`, move all `0`s to the end of it while maintaining the relative order of the non-zero elements.

👉 You must do this **in-place** without making a copy of the array.

---

## 🔹 Example
Input:


[0,1,0,3,12]


Output:


[1,3,12,0,0]


---

## 🔹 My Approach

* Use a pointer `j` to track the **position where next non-zero element should be placed**
* Traverse the array using index `i`
* If `nums[i]` is non-zero:

  * Place it at index `j`
  * Increment `j`

👉 After placing all non-zero elements:

* Fill remaining positions from `j` to end with `0`

---

## 🔹 Key Idea

> “Shift all non-zero elements to the front, then fill the rest with zeros”

---


## 🔹 Dry Run


Input:  [0,1,0,3,12]

Step 1 (place non-zero):
→ [1,3,12, ?, ?]

Step 2 (fill zeros):
→ [1,3,12,0,0]


---

## 🔹 Complexity

* Time Complexity: O(n)
  👉 Single pass through the array

* Space Complexity: O(1)
  👉 In-place, no extra space used

---

## 🔹 Concepts Used

* Two pointers
* In-place array manipulation
* Traversal

---

## 🔹 Edge Cases

* All elements are zero
* No zeros in array
* Single element array

---

## 🔥 Final Insight

👉 Instead of moving zeros, focus on:
**“placing non-zero elements correctly”**

---

## 🧠 What I Learned

* Avoid modifying vector size during traversal
* Use pointer technique for efficient in-place operations
* Always ensure loop variables are updated to avoid infinite loops
