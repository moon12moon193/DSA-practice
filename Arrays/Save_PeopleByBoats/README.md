# Boats to Save People — LeetCode 881

## 📌 Problem Statement

You are given:

* an array `nums` where each value represents a person's weight
* a boat weight limit `limit`

Rules:

* each boat can carry at most 2 people
* total weight inside one boat cannot exceed `limit`

Find:


minimum number of boats required


to save everyone.

---

# 💡 Core Intuition

To minimize boats:

try pairing the lightest person with the heaviest person


If they can fit together:

* both go in one boat

Otherwise:

* heaviest person must go alone

---

# ⚙️ Approach Used

This solution uses:

* Sorting
* Two-pointer technique
* Greedy strategy

---

# 🧠 Why Sorting Helps

After sorting:


smallest → largest


we can efficiently test:




---

# 📌 Pointer Meaning

## `i`

Left pointer:


lightest person


---

## `j`

Right pointer:


heaviest person


---

# ✅ Algorithm Steps

## 1. Sort the Array


sort(nums.begin(), nums.end());


Example:


[3,2,2,1]


becomes:


[1,2,2,3]


---

# 2. Try Pairing Lightest and Heaviest

Check:

nums[i] + nums[j] <= limit


---

## If they fit

Both can share one boat.


count++
i++
j--


---

## If they do NOT fit

Heaviest person must go alone.


count++
j--


Why?

Because:


if lightest cannot fit with heaviest,
nobody else can fit with heaviest either


---

# 3. Continue Until Pointers Meet

Process all people using:


while(i < j)


---

# 4. Handle Remaining Person

If:

i == j


one person is still left.

They need one more boat.

---

# 📌 Example

Input:


nums = [3,2,2,1]
limit = 3


Sorted:


[1,2,2,3]


Process:

* `1 + 3 > 3` → 3 goes alone
* `1 + 2 = 3` → pair together
* remaining `2` goes alone

Total boats:


3


---

# 🧠 Greedy Insight

Always try to save space by pairing:

lightest + heaviest


This minimizes wasted capacity and reduces total boats.

---

# ⏱️ Time Complexity

## Sorting

O(n\log n)

---

## Two-pointer traversal

O(n)

---

# ✅ Overall Time Complexity

Dominated by sorting:

O(n\log n)

---

# 💾 Space Complexity

No extra data structure used.

# ✅

O(1)

---

# 🔑 Concepts Learned

* Greedy strategy
* Two-pointer technique
* Sorting for optimization
* Pairing logic
* Efficient resource allocation

---

# 🚨 Important Insight

If:

lightest + heaviest exceeds limit


then:

heaviest person must go alone


because every other person is heavier than the lightest one.

That observation makes the greedy solution correct.
