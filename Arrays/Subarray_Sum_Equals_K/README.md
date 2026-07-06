# README — Prefix Sum + HashMap (Subarray Sum Equals K)

---

# Problem

Given an integer array `nums` and an integer `k`, return the **number of continuous subarrays whose sum is exactly equal to `k`.**

Example:


nums = [1, 2, 3]
k = 3

Answer = 2

Subarrays:
[1,2]
[3]


---

# Approach

We use two concepts:

1. **Prefix Sum**
2. **HashMap (Frequency Map)**

This reduces the time complexity from **O(n²)** to **O(n)**.

---

# Prefix Sum

The prefix sum is the sum of all elements from index `0` to the current index.

Example:


nums = [2,1,3,2]

Prefix Sums

2
3
6
8


---

# Important Formula

Suppose


Current Prefix Sum = sum

Previous Prefix Sum = prev


Then


Subarray Sum = Current Prefix - Previous Prefix


Since we want


Subarray Sum = k


we get


k = Current Prefix - Previous Prefix


Rearranging,


Previous Prefix = Current Prefix - k


This is why every iteration computes


ques = sum - k;


The question we ask is:

> **"Have I seen a previous prefix sum equal to `sum - k`?"**

If yes, then every occurrence forms one valid subarray.

---

# Why do we use a HashMap?

The hashmap stores


Prefix Sum -> Frequency


Example:


0 -> 1
3 -> 2
5 -> 1


Meaning:

* Prefix sum `0` has appeared once.
* Prefix sum `3` has appeared twice.
* Prefix sum `5` has appeared once.

Looking up a prefix sum in a hashmap takes **O(1)** time.

---

# Why do we store Frequency instead of true/false?

The same prefix sum can appear multiple times.

Example:


nums = [1,-1,1,-1,1]

Prefix Sums

1
0
1
0
1


Prefix sum `0` appears **twice**.

Suppose


Current Prefix = 1
k = 1

Then


Need = 1 - 1 = 0


There are **2 previous prefix sums equal to 0**.

That means there are **2 different subarrays** ending at the current index.

Therefore


ans += f[0];


adds **2**, not **1**.

If we only stored

true


we would know only that the prefix exists, but not how many times it appeared.

Since the problem asks for the **number of subarrays**, we store the **frequency**.

---

# Why do we initialize


f[0] = 1;


Before reading any element,


sum = 0


This represents the **empty prefix** before the array starts.

Imagine an invisible position before index `0`.


        Prefix Sum = 0
             ↓
      | 2 | 1 | 3 |


Storing

f[0] = 1;

means

> **"Before the array begins, one prefix sum of 0 already exists."**

Without this initialization, subarrays starting at index `0` would never be counted.

Example:


nums = [2,1]
k = 3


Current sum becomes


3


Need


3 - 3 = 0


Because


f[0] = 1;


the algorithm correctly counts


[2,1]


as a valid subarray.

---

# Algorithm

For every element:

1. Update the running prefix sum.
2. Compute


sum - k


3. Check how many times this prefix sum has appeared.
4. Add that frequency to the answer.
5. Store the current prefix sum in the hashmap.

---

# Dry Run

Example:


nums = [1,2,1,2]
k = 3


Initial state


sum = 0
ans = 0

HashMap

0 → 1


---

### Index 0


sum = 1

Need = 1-3 = -2

Not found

Store

1 → 1


---

### Index 1


sum = 3

Need = 3-3 = 0

Found once

ans = 1

Store

3 → 1


---

### Index 2


sum = 4

Need = 4-3 = 1

Found once

ans = 2

Store

4 → 1


---

### Index 3

`
sum = 6

Need = 6-3 = 3

Found once

ans = 3

Store

6 → 1


Final Answer


3


---





# Complexity Analysis

### Time Complexity


O(n)


Each element is processed once.

HashMap operations take approximately


O(1)


---

### Space Complexity


O(n)


In the worst case, every prefix sum is different, so the hashmap stores `n` entries.

---

# Key Intuitions to Remember

* **Prefix Sum** = Sum from index `0` to the current index.
* **Subarray Sum** = `Current Prefix − Previous Prefix`.
* **Need Previous Prefix** = `Current Prefix − k`.
* The hashmap stores **prefix sum → frequency**.
* Frequency is stored because **one prefix sum can occur multiple times**, and each occurrence represents a different valid starting point for a subarray.
* `f[0] = 1` represents the **empty prefix before the array begins**, allowing the algorithm to count subarrays that start at index `0`.
