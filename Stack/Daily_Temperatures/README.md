# Daily Temperatures (LeetCode 739)

## Problem

Given an array `temperatures` where `temperatures[i]` represents the temperature on the `iᵗʰ` day, return an array `answer` such that:

- `answer[i]` is the number of days you have to wait after the `iᵗʰ` day to get a **warmer temperature**.
- If there is no future day with a warmer temperature, `answer[i]` should be `0`.

---

## Example 1

**Input**

```cpp
temperatures = [73,74,75,71,69,72,76,73]
```

**Output**

```cpp
[1,1,4,2,1,1,0,0]
```

### Explanation

- Day 0 (73) → Warmer temperature on Day 1 → Wait **1** day.
- Day 1 (74) → Warmer temperature on Day 2 → Wait **1** day.
- Day 2 (75) → Warmer temperature on Day 6 → Wait **4** days.
- Day 3 (71) → Warmer temperature on Day 5 → Wait **2** days.
- Day 4 (69) → Warmer temperature on Day 5 → Wait **1** day.
- Day 5 (72) → Warmer temperature on Day 6 → Wait **1** day.
- Day 6 (76) → No warmer day → **0**.
- Day 7 (73) → No warmer day → **0**.

---

## Example 2

**Input**

```cpp
temperatures = [30,40,50,60]
```

**Output**

```cpp
[1,1,1,0]
```

---

## Example 3

**Input**

```cpp
temperatures = [30,60,90]
```

**Output**

```cpp
[1,1,0]
```

---

# Intuition

For every day, we need to find the **next day** that has a **higher temperature**.

A brute-force solution would compare each day with all future days, resulting in **O(n²)** time.

Instead, we use a **Monotonic Decreasing Stack** to efficiently keep track of candidate days with higher temperatures.

The stack stores **indices**, not temperatures, because we need to calculate the **number of days** between two positions.

---

# Approach

## Step 1: Traverse from Right to Left

Process the temperatures starting from the last day.

At each step, all future days have already been processed.

```cpp
for (int i = n - 1; i >= 0; i--)
```

---

## Step 2: Remove Useless Days

While the stack is not empty and the temperature at the top index is less than or equal to the current temperature,

remove it.

```cpp
while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
    s.pop();
}
```

These days cannot be the next warmer day for the current or any earlier day.

---

## Step 3: Find the Next Warmer Day

If the stack is not empty,

the top of the stack contains the index of the next warmer temperature.

The answer is the difference between the two indices.

```cpp
ans[i] = s.top() - i;
```

---

## Step 4: Push the Current Index

Store the current day's index in the stack.

```cpp
s.push(i);
```

It may become the next warmer day for previous temperatures.

---

# Dry Run

### Input

```
temperatures = [73,74,75,71,69,72,76,73]
```

---

### Process from Right to Left

| Index | Temp | Stack (Indices) | Answer |
|------:|-----:|-----------------|-------:|
| 7 | 73 | 7 | 0 |
| 6 | 76 | 6 | 0 |
| 5 | 72 | 6,5 | 1 |
| 4 | 69 | 6,5,4 | 1 |
| 3 | 71 | 6,5,3 | 2 |
| 2 | 75 | 6,2 | 4 |
| 1 | 74 | 6,2,1 | 1 |
| 0 | 73 | 6,2,1,0 | 1 |

Final answer

```
[1,1,4,2,1,1,0,0]
```

---

# Why Store Indices Instead of Temperatures?

Suppose

```
Index : 0 1 2 3 4
Temp  :75 71 69 72 76
```

For temperature `75`, the next warmer temperature is `76`.

If the stack stores only temperatures,

```
76
```

we know the value is greater, but we **do not know how many days away it is**.

If the stack stores indices,

```
4
```

then

```cpp
answer = 4 - 0 = 4
```

which directly gives the required number of days.

---

# Why Use a Monotonic Stack?

The stack always maintains temperatures in **strictly decreasing order** from bottom to top.

Example

```
Stack

76
72
69
```

When processing temperature `71`,

```
69
```

is removed because it cannot be the next warmer temperature for the current day or any earlier day.

This ensures each index is pushed and popped at most once.

---

# Complexity Analysis

### Time Complexity

Each index is pushed and popped at most one time.

```
O(n)
```

---

### Space Complexity

The stack stores at most `n` indices.

```
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        stack<int> s;

        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (!s.empty()) {
                ans[i] = s.top() - i;
            }

            s.push(i);
        }

        return ans;
    }
};
```

---

# Key Takeaways

- Traverse the array from **right to left**.
- Use a **Monotonic Decreasing Stack** to keep track of candidate warmer days.
- Store **indices**, not temperatures, because the problem asks for the number of **days**.
- Remove all days that are not warmer than the current temperature.
- The top of the stack gives the **next warmer day's index**, and the answer is `nextIndex - currentIndex`.
- Each index is pushed and popped at most once, giving an efficient **O(n)** time solution with **O(n)** extra space.
