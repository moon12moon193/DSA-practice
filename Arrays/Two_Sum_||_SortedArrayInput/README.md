# 🎯 Two Sum II - Input Array Is Sorted

## 🔹 Problem Statement

You are given a **sorted array** of integers and a target value.
Your task is to find **two numbers** such that they add up to the target.

👉 Return the **indices (1-based)** of these two numbers.

---

## 🔹 Example

Input:


numbers = [2,7,11,15], target = 9


Output:


[1,2]


👉 Because:


2 + 7 = 9


---

## 🔹 My Approach (Two Pointer Technique)

* Use two pointers:

  * `i` → start of the array
  * `j` → end of the array

* At each step:

  * Calculate sum = `numbers[i] + numbers[j]`

### Decision:

* If sum == target → answer found
* If sum < target → move `i` forward (increase sum)
* If sum > target → move `j` backward (decrease sum)

---

## 🔹 Key Idea

> “Use sorted property to eliminate unnecessary checks and reduce time complexity”

---

## 🔹 Why This Works

Because the array is sorted:

* Moving left pointer right → increases value
* Moving right pointer left → decreases value

👉 This allows us to make **smart decisions** instead of checking all pairs.

---

## 🔹 Complexity

* Time Complexity: O(n)
  👉 Each element is visited at most once

* Space Complexity:O(1)
  👉 No extra space used

---

## 🔹 Important Points

* Indices are **1-based**, so we return `i+1` and `j+1`
* Loop continues while pointers do not cross
* Always guaranteed one valid solution (as per problem)

---

## 🔹 Edge Cases Considered

* Minimum size array
* Target formed by first and last element
* Large values

---

## 🔥 Final Insight

👉 Instead of checking all pairs (O(n²)),
👉 Use **two pointers + sorted array** to solve efficiently in O(n)

---

## 🧠 What I Learned

* When to use opposite direction pointers
* Importance of sorted arrays in optimization
* How pointer movement reduces search space
