# 📈 Best Time to Buy and Sell Stock (LeetCode #121)

## 🔹 Problem Statement

You are given an array `prices` where `prices[i]` represents the price of a stock on day `i`.

You want to maximize your profit by:

* Choosing a day to buy one stock
* Choosing a different day in the future to sell that stock

Return the maximum profit you can achieve.
If no profit is possible, return `0`.

---

## 🔹 Example

Input

```
prices = [7,1,5,3,6,4]
```

Output:

```
5
```

Explanation:

* Buy at price = 1
* Sell at price = 6
* Profit = 6 - 1 = 5

---

## 🔹 Approach (Simple Intuition)

* Keep track of the **minimum price seen so far**
* For each day:

  * Calculate profit = current price − minimum price
  * Update maximum profit if needed

👉 Idea:

> Always buy at the lowest price before selling

---

## 🔹 Key Concept

* Single pass traversal
* Track minimum value
* Greedy approach

---

## 🔹 Time and Space Complexity

* Time Complexity: O(n)
* Space Complexity: O(1)

---

## 🔹 Edge Cases

* Prices always decreasing → return 0
* Only one element → return 0

---

## 🔹 Summary

* Traverse array once
* Keep updating minimum price
* Calculate best possible profit


