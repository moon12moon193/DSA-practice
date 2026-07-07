# LeetCode - 974. Subarray Sums Divisible by K

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **number of non-empty subarrays** whose sum is divisible by `k`.

---

## Intuition

A subarray sum can be written as:

Subarray Sum = Current Prefix Sum - Previous Prefix Sum


For a subarray to be divisible by `k`:


(Current Prefix Sum - Previous Prefix Sum) % k == 0


This means:


Current Prefix Sum % k == Previous Prefix Sum % k


So, at every index:

1. Compute the current prefix sum.
2. Compute its remainder (`prefixSum % k`).
3. If the same remainder has appeared before, then every previous occurrence forms one valid subarray ending at the current index.
4. Store the frequency of the current remainder.

---

## Why Do We Store Remainders Instead of Prefix Sums?

For this problem, we do **not** need the exact value of the previous prefix sum.

We only need to know whether another prefix sum has the **same remainder** when divided by `k`.

Therefore, the hashmap stores:


remainder -> frequency


instead of:

prefixSum -> frequency


---

## Why Do We Initialize `f[0] = 1`?

Before processing the array, the prefix sum is:


0


Its remainder is:


0 % k = 0


This represents the **empty prefix**.

It allows us to count subarrays that start from index `0` and whose sum is divisible by `k`.

---

## Why Handle Negative Remainders?

In C++, the `%` operator can return a negative remainder.

Example:


-6 % 5 = -1


But mathematically, `-1` and `4` belong to the same modulo class for `k = 5`.

To ensure all equivalent remainders use the same hashmap key, normalize negative remainders:


if (rem < 0)
{
    rem += k;
}


This converts the remainder into the range:


0 ... k-1


---

## Algorithm

1. Initialize:

   * `sum = 0`
   * `count = 0`
   * HashMap `f`
   * `f[0] = 1`

2. Traverse the array:

   * Add the current element to the prefix sum.
   * Compute the remainder.
   * Normalize it if negative.
   * Add the frequency of the same remainder to the answer.
   * Increase the frequency of the current remainder.

3. Return the total count.

---



## Complexity Analysis

**Time Complexity**


O(n)


Each element is processed exactly once.

**Space Complexity**


O(k)


In the worst case, the hashmap stores at most `k` distinct remainders (`0` to `k - 1`).

---

## Key Takeaways

* Prefix Sum converts every subarray problem into a difference of two prefix sums.
* For divisibility, **equal remainders** are the key observation.
* The hashmap stores the **frequency of previous prefix sum remainders**.
* `f[0] = 1` handles subarrays starting from index `0`.
* Normalize negative remainders so mathematically equivalent remainders map to the same hashmap key.
