# 🌟 Happy Number (LeetCode 202)

## 📌 Problem Statement

A number is called a **Happy Number** if:

- Starting with any positive integer  
- Replace the number with the **sum of squares of its digits**
- Repeat the process  
- If it eventually reaches **1**, it is a Happy Number  
- If it enters a cycle that does not include 1, it is NOT a Happy Number  

---

## 🧠 Core Idea

We use **Floyd’s Cycle Detection Algorithm (Slow & Fast Pointer)** to detect cycles in the transformation process.

Instead of storing all previous numbers, we detect repetition using pointers.

---

## 🔥 Key Insight

Each number generates a "next number" like a linked chain:

So the problem becomes:

> Detect whether this chain reaches `1` or enters a cycle.

---

## ⚙️ Approach

### Step 1: Digit Square Sum Function

We compute the next number by summing squares of digits.

---

### Step 2: Floyd Cycle Detection

We use two pointers:

- 🐢 Slow pointer → moves 1 step
- 🐇 Fast pointer → moves 2 steps

They traverse the sequence until:

- They meet (cycle detected)

---

### Step 3: Check Result

After pointers meet:

- If value is `1` → ✅ Happy Number  
- Otherwise → ❌ Not a Happy Number  

---


 Complexity Analysis
Time Complexity
O(log n × cycle length)

Each step processes digits of a number.

Space Complexity
O(1)

No extra data structures used.

---

---
Example
Input: 19

19 → 82 → 68 → 100 → 1 → 1 → 1

Output: True

---
Summary

 No extra memory used
 
 Cycle detection via pointers
 
 Clean mathematical simulation
 
 Efficient and optimal approach
 
