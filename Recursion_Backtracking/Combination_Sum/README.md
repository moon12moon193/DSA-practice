# Recursion & Backtracking — Combination Generation

## Problem

Given an array of positive integers `candidates` and a target value `target`, generate all combinations of numbers whose sum is exactly equal to the target.

A candidate can be selected **multiple times**.

For example:

```text
candidates = [2, 3, 6, 7]
target = 7
```

Valid combinations include:

```text
[2, 2, 3]
[7]
```

The order of elements inside a combination does not matter.

---

## Approach

This solution uses:

* Recursion
* Backtracking
* Include/Exclude decision making
* Running sum

At every index, there are two choices:

```text
1. Don't choose candidates[index]
2. Choose candidates[index]
```

The recursion explores both possibilities.

The important difference is that when we **choose** the current candidate, we call:

```cpp
fun(index, ...)
```

instead of:

```cpp
fun(index + 1, ...)
```

This allows the same candidate to be selected again.

---

# Important Variables

The recursive function is:

```cpp
fun(index, temp, result, candidates, target, sum)
```

### `index`

The current position in the `candidates` array.

### `temp`

Stores the current combination.

### `result`

Stores all valid combinations.

### `candidates`

Contains the available numbers.

### `target`

The required sum.

### `sum`

Stores the sum of the numbers currently inside `temp`.

---

# Base Case

The recursion stops when every candidate has been considered.

```cpp
if(index == n){
    if(sum == target){
        result.push_back(temp);
        return;
    }
    return;
}
```

If:

```text
sum == target
```

then the current combination is valid and is added to the result.

For example:

```text
temp = [2, 2, 3]
sum = 7
target = 7
```

Therefore:

```text
[2, 2, 3]
```

is stored.

---

# Choice 1 — Don't Choose

The first recursive call is:

```cpp
fun(index + 1, temp, result, candidates, target, sum);
```

This means:

```text
Don't select candidates[index]
```

Move directly to the next candidate.

For example:

```text
candidates = [2, 3, 6, 7]
             ↑
           index
```

If we don't choose `2`, we move to:

```text
candidates = [2, 3, 6, 7]
                ↑
              index
```

---

# Choice 2 — Choose

The second possibility is to choose the current candidate:

```cpp
temp.push_back(candidates[index]);
sum = sum + candidates[index];

fun(index, temp, result, candidates, target, sum);
```

Notice that the recursive call uses:

```cpp
fun(index, ...)
```

rather than:

```cpp
fun(index + 1, ...)
```

This is very important.

Because the index doesn't change, the same candidate can be selected again.

For example:

```text
candidates = [2, 3, 6, 7]
```

We can select:

```text
2
2
2
2
```

if the target allows it.

---

# Why `index` Does Not Increase After Choosing?

Suppose:

```text
candidates = [2, 3, 6, 7]
target = 7
```

After selecting `2`:

```text
temp = [2]
sum = 2
```

We can select `2` again:

```text
temp = [2, 2]
sum = 4
```

Again:

```text
temp = [2, 2, 2]
sum = 6
```

Then another `2` would make:

```text
sum = 8
```

which is greater than the target.

So eventually the recursion must move on or stop.

This ability to reuse the same index is what allows combinations such as:

```text
[2, 2, 3]
```

to be generated.

---

# Backtracking

After exploring the branch where the candidate was selected, we undo that choice:

```cpp
temp.pop_back();
sum = sum - candidates[index];
```

This is the **backtracking step**.

The complete pattern is:

```text
Choose
   ↓
Explore
   ↓
Undo
```

In your code:

```cpp
temp.push_back(candidates[index]);

sum = sum + candidates[index];

fun(index, temp, result, candidates, target, sum);

temp.pop_back();

sum = sum - candidates[index];
```

---

# Why Do We Undo `sum`?

Suppose:

```text
sum = 2
```

and we choose another `2`:

```text
sum = 4
```

After returning from recursion, we need to restore the previous state:

```text
sum = 2
```

That's why:

```cpp
sum = sum - candidates[index];
```

is required.

Without this, the `sum` would incorrectly contain values from a previous recursive branch.

---

# Recursion Tree

Consider:

```text
candidates = [2, 3]
target = 5
```

The recursion starts with:

```text
                    []
                   /  \
                skip   choose 2
                 |        |
                 3       [2]
                / \       / \
             skip choose2 skip choose2
```

The choose branch can repeatedly use `2` because the index remains unchanged.

Eventually combinations such as:

```text
[2, 3]
```

can be generated.

---

# Dry Run

Consider:

```text
candidates = [2, 3]
target = 5
```

Initially:

```text
index = 0
temp = []
sum = 0
```

Current candidate:

```text
2
```

### Don't choose `2`

Move to:

```text
index = 1
sum = 0
```

Now candidate is `3`.

If we choose `3`:

```text
temp = [3]
sum = 3
```

The sum is not `5`, so the branch eventually ends.

---

### Choose `2`

Backtrack to the original state and choose `2`:

```text
temp = [2]
sum = 2
```

Call recursion again with the **same index**:

```cpp
fun(index, ...)
```

Now choose `2` again:

```text
temp = [2, 2]
sum = 4
```

Again, the same candidate can be chosen.

Eventually the recursion can move forward and choose `3`:

```text
temp = [2, 3]
sum = 5
```

Now:

```text
sum == target
```

so:

```text
[2, 3]
```

is added to `result`.

---

# C++ Solution

```cpp
class Solution {
public:

    void fun(
        int index,
        vector<int>& temp,
        vector<vector<int>>& result,
        vector<int>& candidates,
        int target,
        int sum
    ) {

        int n = candidates.size();

        // Base case
        if (index == n) {
            if (sum == target) {
                result.push_back(temp);
            }
            return;
        }

        // Don't choose current candidate
        fun(
            index + 1,
            temp,
            result,
            candidates,
            target,
            sum
        );

        // Choose current candidate
        if (sum <= target) {

            temp.push_back(candidates[index]);

            sum = sum + candidates[index];

            // Same index because a candidate can be reused
            fun(
                index,
                temp,
                result,
                candidates,
                target,
                sum
            );

            // Backtrack
            temp.pop_back();

            sum = sum - candidates[index];
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {

        vector<vector<int>> result;
        vector<int> temp;

        fun(
            0,
            temp,
            result,
            candidates,
            target,
            0
        );

        return result;
    }
};
```

---

# Important Observation

Your recursion follows an **include/exclude pattern**.

At every index:

```text
                 Current Candidate
                    /       \
                   /         \
             Don't Choose   Choose
                 |             |
             index + 1       index
```

The difference between the two calls is important:

```cpp
// Don't choose
fun(index + 1, ...);

// Choose
fun(index, ...);
```

Because the candidate can be reused, choosing it does **not** move to the next index.

---

# Pruning

Your code contains:

```cpp
if(sum <= target)
```

This prevents the recursion from continuing after the current sum has already exceeded the target.

Because all candidates are positive, once:

```text
sum > target
```

adding more numbers can never bring the sum back down to the target.

A slightly stronger version can be:

```cpp
if(sum + candidates[index] <= target)
```

before making the choice.

This avoids adding a candidate when it would immediately make the sum too large.

---

# Complexity Analysis

Let `T` represent the target and `N` represent the number of candidates.

The number of recursive states can grow exponentially because each candidate can be either:

```text
chosen
```

or:

```text
skipped
```

and candidates may be selected repeatedly.

Therefore, the time complexity is exponential in the worst case.

The recursion depth depends on how many times the smallest candidate can be selected.

If the smallest candidate is `m`, the maximum depth is approximately:

```text
T / m
```

The result storage also depends on the number and size of valid combinations.

---

# Key Takeaways

* This solution uses **recursion + backtracking**.
* At every candidate there are two choices: **choose** or **skip**.
* `temp` stores the current combination.
* `sum` tracks the current combination's total.
* `push_back()` makes a choice.
* The recursive call explores that choice.
* `pop_back()` undoes the choice.
* `sum` must also be restored after backtracking.
* Calling `fun(index, ...)` allows the same candidate to be used multiple times.
* Calling `fun(index + 1, ...)` moves to the next candidate.
* Because candidates are positive, sums greater than the target can be pruned.
* The fundamental backtracking pattern is:

```text
Choose → Explore → Undo
```
