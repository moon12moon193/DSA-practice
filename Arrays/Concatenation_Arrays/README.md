# 🔗 Concatenation of Array (LeetCode #1929)

## 🔹 Problem Statement

Given an integer array `nums` of length `n`, return an array `ans` of length `2n` where:


ans[i] = nums[i]
ans[i + n] = nums[i]


👉 In simple words:
You need to create a new array which is the concatenation of the array with itself.

---

## 🔹 Example

Input:


nums = [1,2,3]


Output:


[1,2,3,1,2,3]


---

## 🔹 My Approach

* Store the original size of array in variable `n`
* Use a pointer `j` to traverse from `0` to `n-1`
* In each iteration:

  * Append (`push_back`) the element `nums[j]` to the end of the array

👉 Important:

* We only loop till original `n`
* Even though array size increases, we avoid infinite loop by using fixed `n`

---



## 🔹 Dry Run


Input: [1,2,3]
n = 3

Step 1 → push 1 → [1,2,3,1]
Step 2 → push 2 → [1,2,3,1,2]
Step 3 → push 3 → [1,2,3,1,2,3]


---

## 🔹 Complexity

* Time Complexity: O(n)
  👉 Loop runs `n` times

* Space Complexity: O(1) extra
  👉 No additional data structure used (modifying same vector)

---

## 🔹 Key Concepts

* Array traversal
* Understanding dynamic size of vector
* Using `push_back()` safely with fixed loop boundary

---

## 🔹 Edge Cases

* Empty array
* Single element array
* Large input size

---

## 🔥 Final Insight

👉 Store original size before modifying vector
👉 Otherwise loop may become infinite

---

## 🧠 What I Learned

* Difference between `nums.size()` and stored `n`
* How vector grows dynamically
* Safe way to modify array during iteration
