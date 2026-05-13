# 3Sum Closest — LeetCode 16

## 📌 Problem Statement

Given an integer array `nums` and an integer `target`, find three integers in the array such that:


their sum is closest to the target


Return:


the SUM of those three integers


You only need one closest sum.

---

# 💡 Core Intuition

For every possible triplet:


(nums[i], nums[left], nums[right])


calculate:


sum = nums[i] + nums[left] + nums[right]


Then measure how close the sum is to target using:



The triplet having the minimum distance is the answer.

---

# ⚙️ Approach Used

This solution uses:

* Sorting
* Fixed pointer
* Two-pointer technique
* Closest-distance tracking

---

# 🧠 Why Sorting Helps

After sorting:

* moving left pointer increases sum
* moving right pointer decreases sum

This allows efficient searching instead of checking all triplets manually.

---

# ✅ Algorithm Steps

## 1. Sort the Array


sort(nums.begin(), nums.end());


Example:


[-1,2,1,-4]


becomes:


[-4,-1,1,2]


---

# 2. Fix First Element

Use loop variable `i` as first element of triplet.


for(int i=0; i<nums.size()-2; i++)


---

# 3. Skip Duplicate Fixed Values


if(i > 0 && nums[i] == nums[i-1])
{
    continue;
}


Avoids unnecessary repeated work.

---

# 4. Use Two Pointers

For every fixed `i`:


left = i + 1
right = nums.size() - 1


Now search for best possible pair.

---

# 5. Calculate Sum and Distance


sum = nums[i] + nums[left] + nums[right]


Distance from target:



If current distance is smaller than previous minimum:

* update minimum distance
* store current sum

---

# 6. Move Pointers Intelligently

## If sum is smaller than target


left++


Need larger value.

---

## If sum is larger than target


right--


Need smaller value.

---

## If exact target found

Closest possible answer achieved.

---

# 📌 Example

Input:


nums = [-1,2,1,-4]
target = 1


Sorted:


[-4,-1,1,2]


Possible sums:


-4 + (-1) + 2 = -3
-4 + 1 + 2 = -1
-1 + 1 + 2 = 2


Distances from target:


|-3 - 1| = 4
|-1 - 1| = 2
|2 - 1| = 1


Closest sum:


2


So answer becomes:


2


---

# ⏱️ Time Complexity

## Sorting

O(n\log n)

---

## Outer Loop + Two Pointers

For every `i`, pointers traverse array once.

O(n^2)

---

# ✅ Overall Time Complexity

O(n^2)

---

# 💾 Space Complexity

No extra data structures used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Two-pointer technique
* Sorting for optimization
* Closest value searching
* Greedy pointer movement
* Duplicate handling

---

# 🚨 Key Insight

The goal is NOT:


find exact target


The goal is:


find the sum having minimum distance from target


This distance is measured using absolute difference.
