# 🧹 Remove Duplicates from Sorted Array (LeetCode #26)

## 🔹 Problem Statement

Given a sorted array `nums`, remove the duplicates in-place such that each unique element appears only once.

Return the number of unique elements `k`.

* The first `k` elements of `nums` should contain the unique elements
* Remaining elements can be ignored

---

## 🔹 Example

Input:

```
nums = [0,0,1,1,1,2,2,3,3,4]
```

Output:

```
k = 5
nums = [0,1,2,3,4,_,_,_,_,_]
```

---

## 🔹 My Approach

* Start from index `1` (since first element is always unique)
* Compare current element with previous element
* If they are different:

  * Increment `k`
  * Place the current element at index `k`

👉 Idea:

> Keep track of position where next unique element should be placed

---


## 🔹 Key Concepts

* In-place modification
* Array traversal
* Comparing adjacent elements

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---


## 🔹 Summary

* Traverse array once
* Compare with previous element
* Store unique values at the front
* Return count of unique elements


