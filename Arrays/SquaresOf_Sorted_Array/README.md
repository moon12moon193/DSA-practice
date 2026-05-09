# Squares of a Sorted Array — LeetCode 977

## 📌 Problem Statement

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

### Example

Input:


[-4,-1,0,3,10]


Output:


[0,1,9,16,100]


---

# 💡 Approach Used

This solution uses a **merge-style technique**.

The array is already sorted, but after squaring:

* negative numbers become positive
* order may break

Example:


[-4,-1,0,3]


After squaring:


[16,1,0,9]


Now:

* left side (squared negatives) is in decreasing order
* right side is already increasing

So we merge both parts similarly to merge sort.

---

# ⚙️ Steps of Algorithm

## 1. Find First Non-Negative Element


while(i < nums.size() && nums[i] < 0)


This divides array into:

* negative part
* non-negative part

---

## 2. Square Every Element


nums[k] = nums[k] * nums[k];


Now all values become positive.

---

## 3. Handle Edge Cases

### Case 1: No negative numbers

Array is already sorted after squaring.


if(i == 0)


---

### Case 2: All numbers were negative

After squaring, order becomes reversed.
reverse(nums.begin(), nums.end());


---

## 4. Merge Both Sorted Parts

Use:

* `j` → squared negative side
* `i` → squared positive side

Compare both and insert smaller value into result array.

This produces final sorted squares array.

---

# 🧠 Time Complexity

## Finding partition


O(n)


## Squaring elements


O(n)


## Merge process

O(n)


## Overall Time Complexity

O(n)


---

# 💾 Space Complexity

Extra result vector used:


O(n)


---

# ✅ Key Concepts Used

* Two pointers
* Merge technique
* Array traversal
* In-place squaring
* Edge case handling

---

# 🚨 Important Bug Avoided

Correct condition order:


while(i < nums.size() && nums[i] < 0)


Bounds check must come first to avoid out-of-range access.

---

# ✅ Final Notes

This solution efficiently solves the problem in linear time using a merge-style strategy inspired by merge sort.

