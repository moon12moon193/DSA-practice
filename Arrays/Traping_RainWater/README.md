# Trapping Rain Water — LeetCode 42

## 📌 Problem Statement

You are given an array `height` where each value represents the height of a building/bar.

After rain falls, water can get trapped between taller bars.

Your task is to calculate:


total amount of trapped rain water


---

# 💡 Core Intuition

Water can only be trapped if:

* there is a taller bar on the left
* and a taller bar on the right

The trapped water at any position depends on:


minimum(left maximum height, right maximum height)


minus:


current bar height


Water formula:

\text{Water} = \min(\text{leftMax},\text{rightMax}) - \text{height[i]}

---

# ⚙️ Approach Used

This solution uses:

* Two pointers
* Left maximum tracking
* Right maximum tracking

---

# 🧠 Key Observation

The smaller side determines water storage.

If:

leftMax < rightMax


then:


left side decides trapped water


because right side is already tall enough.

Similarly:


rightMax <= leftMax


means:


right side decides trapped water


---

# ✅ Variables Used

## `left`

Starts from beginning.

---

## `right`

Starts from end.

---

## `leftMax`

Maximum height seen from left side.

---

## `rightMax`

Maximum height seen from right side.

---

## `ans`

Stores total trapped water.

---

# ✅ Algorithm Steps

## 1. Update Left and Right Maximum
leftMax = max(leftMax, height[left]);
rightMax = max(rightMax, height[right]);


---

# 2. Compare Left and Right Maximums

## If leftMax is smaller


leftMax < rightMax


then trapped water depends on left side.

Water trapped:

{leftMax} - {height[left]}

Then move:


left++


---

# 3. Otherwise

Water depends on right side.

Water trapped:

\text{rightMax} - \text{height[right]}

Then move:


right--


---

# 📌 Example

Input:


[0,1,0,2,1,0,1,3,2,1,2,1]


Water trapped between bars:


6 units


---

# 🧠 Why Two Pointers Work

Instead of calculating left and right maximum separately for every position:


use running maximums from both sides


This reduces unnecessary repeated work.

---

# ⏱️ Time Complexity

Array traversed once.

# ✅

O(n)

---

# 💾 Space Complexity

No extra arrays used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Two-pointer technique
* Prefix/suffix maximum idea
* Water trapping logic
* Greedy traversal
* Optimized space usage

---

# 🚨 Important Insight

Water level at a position depends on:


the smaller boundary


because water spills from the lower side first.

That is the key logic behind the solution.
