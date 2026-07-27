# Koko Eating Bananas (LeetCode 875)

## Problem

Koko loves eating bananas. There are `n` piles of bananas, where `piles[i]` represents the number of bananas in the `iᵗʰ` pile.

Koko can decide an eating speed `k` (bananas per hour).

Every hour:

- She chooses **one pile**.
- She eats **up to `k` bananas** from that pile.
- If the pile contains fewer than `k` bananas, she eats the entire pile and does **not** continue to another pile during that hour.

Given an integer `h` representing the maximum number of hours available, return the **minimum integer eating speed `k`** so that Koko can finish all the bananas within `h` hours.

---

## Example 1

**Input**

```cpp
piles = [3,6,7,11]
h = 8
```

**Output**

```cpp
4
```

### Explanation

At a speed of `4` bananas/hour:

- Pile 3 → 1 hour
- Pile 6 → 2 hours
- Pile 7 → 2 hours
- Pile 11 → 3 hours

Total:

```text
1 + 2 + 2 + 3 = 8 hours
```

---

## Example 2

**Input**

```cpp
piles = [30,11,23,4,20]
h = 5
```

**Output**

```cpp
30
```

---

## Example 3

**Input**

```cpp
piles = [30,11,23,4,20]
h = 6
```

**Output**

```cpp
23
```

---

# Intuition

We are **not** searching for a pile or an index.

Instead, we are searching for the **minimum valid eating speed**.

- If Koko eats too slowly, the total hours required will be **greater than `h`**.
- If Koko eats fast enough, she can finish within `h` hours.

This creates a **monotonic property**:

```text
Speed increases  →  Hours decrease
```

Since the answer changes monotonically, Binary Search can be applied on the range of possible speeds.

---

# Approach

## Step 1: Define the Search Space

The minimum possible speed is

```cpp
1
```

The maximum possible speed is the largest pile.

```cpp
max(piles)
```

So,

```cpp
low = 1;
high = maximum pile;
```

---

## Step 2: Calculate Total Hours

For every pile,

```text
Hours = ceil(pile / speed)
```

Instead of using floating-point operations, compute it as:

```cpp
hours += pile / speed;

if (pile % speed != 0)
    hours++;
```

Accumulate the hours required for all piles.

---

## Step 3: Perform Binary Search

Choose

```cpp
mid = low + (high - low) / 2;
```

Calculate the total hours needed using speed `mid`.

### Case 1

If

```cpp
hours > h
```

the speed is too slow.

Search the right half.

```cpp
low = mid + 1;
```

---

### Case 2

Otherwise,

the speed is sufficient.

Store it as a possible answer and try to find a smaller valid speed.

```cpp
res = mid;
high = mid - 1;
```

---

## Step 4: Return the Answer

When Binary Search finishes,

`res` stores the minimum eating speed.

---

# Dry Run

### Input

```text
piles = [3,6,7,11]
h = 8
```

---

### Initial State

```text
low = 1
high = 11
```

---

### Iteration 1

```text
mid = 6
```

Hours required:

```text
3 → 1
6 → 1
7 → 2
11 → 2

Total = 6
```

Since

```text
6 <= 8
```

Store

```text
res = 6
```

Search for a smaller speed.

```text
high = 5
```

---

### Iteration 2

```text
low = 1
high = 5

mid = 3
```

Hours:

```text
3 → 1
6 → 2
7 → 3
11 → 4

Total = 10
```

Since

```text
10 > 8
```

Speed is too slow.

```text
low = 4
```

---

### Iteration 3

```text
low = 4
high = 5

mid = 4
```

Hours:

```text
3 → 1
6 → 2
7 → 2
11 → 3

Total = 8
```

Since

```text
8 <= 8
```

Store

```text
res = 4
```

Search left.

```text
high = 3
```

Loop ends.

Return

```text
4
```

---

# Why Use `long long` for Total Hours?

The total number of hours can become very large.

For example,

```cpp
piles = [805306368,805306368,805306368]
speed = 1
```

Hours become

```text
805306368
+805306368
+805306368
=2415919104
```

This exceeds the maximum value of an `int` (`2,147,483,647`).

Using

```cpp
long long
```

prevents integer overflow.

---

# Complexity Analysis

### Time Complexity

Finding the maximum pile:

```text
O(n)
```

Binary Search performs

```text
O(log(maxPile))
```

iterations.

Each iteration scans all piles.

Overall:

```text
O(n × log(maxPile))
```

---

### Space Complexity

Only a few extra variables are used.

```text
O(1)
```

---

# C++ Solution

```cpp
class Solution {
public:
    long long TotalTime(vector<int>& piles, int mid) {

        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {

            int ans = piles[i] / mid;
            hours += ans;

            if (piles[i] % mid != 0) {
                hours++;
            }
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int maxi = INT_MIN;
        int res = -1;

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        int high = maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = TotalTime(piles, mid);

            if (hours > h) {

                low = mid + 1;

            } else {

                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};
```

---

# Key Takeaways

- Binary Search can be applied to **search on answers**, not just array indices.
- The search space is the range of possible eating speeds (`1` to the maximum pile size).
- For each candidate speed, calculate the total hours required.
- If the required hours exceed `h`, increase the speed; otherwise, record the speed and try a smaller one.
- Use `long long` when accumulating total hours to avoid integer overflow.
- The solution runs in **O(n × log(maxPile))** time with **O(1)** extra space.
