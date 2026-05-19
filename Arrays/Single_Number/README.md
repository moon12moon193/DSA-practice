# Single Number — LeetCode 136

## 📌 Problem Statement

You are given a non-empty integer array `nums`.

Every element appears:


exactly twice


except for one element that appears:


only once


Your task is to find and return that single element.

---

# 💡 Core Intuition

If the array is sorted:


duplicate elements become adjacent


Then:

* paired elements appear together
* the unique element will be the one that does not match neighbors

---

# ⚙️ Approach Used

This solution uses:

* Sorting
* Neighbor comparison

---

# 🧠 Why Sorting Helps

Example:

Input:

[4,1,2,1,2]


After sorting:


[1,1,2,2,4]


Now duplicate values appear side-by-side,
making the single number easy to detect.

---

# ✅ Special Cases Handled

## Case 1 — Only One Element

If array size is:


1


that element is automatically the answer.

---

# Case 2 — First Element is Unique

Check:


nums[0] != nums[1]


If true:


first element is single number


---

# Case 3 — Last Element is Unique

During traversal:

i == nums.size()-1


and current value differs from previous value.

Then last element is unique.

---

# ✅ Main Logic

For middle elements:

Check whether current element differs from:

* previous element
* next element

Condition:


nums[i] != nums[i-1]
&&
nums[i] != nums[i+1]


If true:


current element appears only once


Return it.

---

# 📌 Example

Input:


[2,2,1]


Sorted:


[1,2,2]


First element:


1 != 2


So answer becomes:


1


---

# 📌 Another Example

Input:


[4,1,2,1,2]


Sorted:


[1,1,2,2,4]


Traversal finds:


4 has no matching neighbor


Answer:


4


---

# ⏱️ Time Complexity

## Sorting

O(n\log n)

---

## Traversal

O(n)

---

# ✅ Overall Time Complexity

Dominated by sorting:

O(n\log n)

---

# 💾 Space Complexity

No extra data structures used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Sorting for grouping duplicates
* Neighbor comparison
* Edge-case handling
* Sequential traversal
* Unique element detection

---

# 🚨 Important Insight

After sorting:


every duplicate appears beside its pair


So the single number becomes:


the only element without matching neighbors

