# Merge Sorted Array — LeetCode 88

## 📌 Problem Statement

You are given:

* `nums1` of size `m + n`
* first `m` elements of `nums1` are sorted valid elements
* remaining `n` positions are empty placeholders (`0`)
* another sorted array `nums2` of size `n`

Your task:

merge nums2 into nums1


such that final array becomes completely sorted.

---

# 💡 Core Intuition

Both arrays are already sorted.

So instead of sorting again:


compare elements one-by-one and merge intelligently


This is similar to:

* merge step of merge sort
* combining two sorted lists

---

# ⚙️ Approach Used

This solution uses:

* Two pointers
* Temporary array
* Sequential merging

---

# 📌 Pointer Meaning

## `i`

Traverses valid elements of:


nums1


---

## `j`

Traverses:


nums2


---

## `k`

Tracks insertion position inside:


temp


---

# ✅ Algorithm Steps

## 1. Create Temporary Array


vector<int> temp(m+n,0);


Stores merged sorted result.

---

# 2. Compare Elements from Both Arrays

While both arrays still contain elements:


while(i < m && j < n)


---

## If nums1 element is smaller


temp[k] = nums1[i]


Move:


i++
k++


---

## Otherwise




Move:

j++
k++


---

# 3. Copy Remaining Elements

After one array finishes,
copy leftover elements from other array.

---

## Remaining nums1 elements


while(i < m)


---

## Remaining nums2 elements

while(j < n)


---

# 4. Copy Final Result Back into nums1


nums1[l] = temp[l]


Now `nums1` contains merged sorted array.

---

# 📌 Example

Input:


nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3


Process:

* compare 1 and 2 → take 1
* compare 2 and 2 → take 2
* compare 2 and 3 → take 2
* compare 3 and 5 → take 3
* remaining → 5,6

Final array:


[1,2,2,3,5,6]


---

# 🧠 Why This Works

Since both arrays are already sorted:


smallest remaining element always appears at current pointer


So merging can happen in one traversal.

---

# ⏱️ Time Complexity

Each element processed once.

# ✅

O(m+n)

---

# 💾 Space Complexity

Temporary array used.

# ✅

O(m+n)

---

# 🔑 Concepts Learned

* Merge process
* Two-pointer traversal
* Sorted array processing
* Merge sort idea
* Sequential comparison logic

---

# 🚨 Important Insight

Because arrays are already sorted:

```text id="z7a8b9"
only current smallest elements need comparison
```

No re-sorting of whole array is required.
