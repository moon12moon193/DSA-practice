# Maximum Product Subarray

## Problem

Given an integer array `nums`, find the **contiguous subarray** that has the largest product and return that product.

---

## Intuition

Unlike the Maximum Sum Subarray problem, the product can change dramatically because of **negative numbers**.

- A **positive** number keeps the sign the same.
- A **negative** number swaps the largest and smallest products.
- A **zero** resets the product.

Because of this, we must keep track of:

- **Maximum product ending at the current index**
- **Minimum product ending at the current index**

The minimum product is important because multiplying it by a negative number may produce the next maximum product.

---

## Approach

For every element, three possibilities exist:

1. Start a new subarray from the current element.
2. Extend the previous minimum product subarray.
3. Extend the previous maximum product subarray.

For each index:

- Compute all three possible products.
- Update the current minimum product.
- Update the current maximum product.
- Update the global maximum product.

---

## Algorithm

1. Initialize:
   - `minProduct = nums[0]`
   - `maxProduct = nums[0]`
   - `GlobalProduct = nums[0]`

2. Traverse the array from index `1`.

3. Compute:
   - Current element
   - Current element × previous minimum product
   - Current element × previous maximum product

4. Update:
   - Current minimum product
   - Current maximum product

5. Update the global answer.

6. Return the global maximum product.

---



---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Takeaways

- Keep both the **minimum** and **maximum** products ending at each index.
- A negative number can convert the smallest product into the largest one.
- The answer is updated after processing every element.
- This approach solves the problem in linear time using constant extra space.
