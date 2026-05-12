# Container With Most Water — LeetCode 11

## 📌 Problem Statement

You are given an integer array `height`.

Each value represents the height of a vertical line.

Find two lines that together form a container holding the maximum amount of water.

The amount of water stored depends on:

* shorter height
* distance between lines

---

# 💡 Core Idea

Water level is determined by the **smaller height** because water overflows from the shorter side.

Area formula:



Where:

* `height` = minimum of the two heights
* `width` = distance between indexes

---

# ⚙️ Approach Used

This solution uses the **Two Pointer Technique**.

## Initial Pointers


i = 0
j = height.size() - 1


* `i` → left pointer
* `j` → right pointer

Initially width is maximum.

---

# 🧠 Key Observation

Area depends on:


smaller height × width


If one side is shorter:

* moving taller side cannot help
* width decreases
* smaller height remains limiting factor

So we move the pointer having smaller height.

---

# ✅ Algorithm Steps

## 1. Calculate Area

height = min(height[i], height[j])
width = j - i
area = height * width


Update maximum area.

---

## 2. Move Smaller Height Pointer

### If left height is smaller


i++


Try finding taller left wall.

---

### Otherwise


j--


Try finding taller right wall.

---

# 📌 Example

Input:

[1,8,6,2,5,4,8,3,7]


Initially:


left = 1
right = 7
width = 8
area = 8


Pointers keep moving toward center while checking larger areas.

Maximum area becomes:


49


formed by:

* height = 7
* width = 7

---

# 🧠 Why Two Pointers Work

Brute force checks every pair:

O(n²)


But this approach intelligently removes impossible cases.

At every step:

* one pointer moves
* width decreases
* we try improving smaller height

This gives optimal solution.

---

# ⏱️ Time Complexity

Pointers traverse array once.

# ✅


O(n)


---

# 💾 Space Complexity

No extra array used.

# ✅

O(1)


---

# 🔑 Concepts Learned

* Two pointer technique
* Greedy observation
* Area calculation
* Optimizing brute force solution

---

# 🚨 Important Insight

Always move the pointer with smaller height because:

* area is limited by smaller wall
* moving taller wall cannot increase current limiting height

This is the key logic behind the optimal solution.
