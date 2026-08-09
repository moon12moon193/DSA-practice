# Fibonacci Number — Recursion

## Problem

Given an integer `n`, calculate the `n`th Fibonacci number using **recursion**.

The Fibonacci sequence is defined as:

```text
F(0) = 0
F(1) = 1

F(n) = F(n - 1) + F(n - 2)
```

The sequence begins:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

---

## Approach

This solution uses **recursion**.

There are two important parts:

### Base Case

When `n` is `0` or `1`, the answer is already known:

```cpp
if (n == 0 || n == 1) {
    return n;
}
```

So:

```text
fib(0) → 0
fib(1) → 1
```

---

### Recursive Case

For every value greater than `1`, calculate:

```text
fib(n - 1) + fib(n - 2)
```

```cpp
int firstLast = fib(n - 1);
int secondLast = fib(n - 2);

int ans = firstLast + secondLast;
```

Then return the result.

---

## How Recursion Works

Consider:

```text
fib(5)
```

The function breaks the problem into smaller problems:

```text
                 fib(5)
                /      \
            fib(4)     fib(3)
            /   \       /   \
        fib(3) fib(2) fib(2) fib(1)
        ...
```

The recursion continues until it reaches:

```text
fib(1)
fib(0)
```

These are the base cases.

Then the results are returned back up the recursion tree.

---

## Dry Run

For:

```text
fib(4)
```

We calculate:

```text
fib(4)
= fib(3) + fib(2)
```

Then:

```text
fib(3)
= fib(2) + fib(1)
```

And:

```text
fib(2)
= fib(1) + fib(0)
```

Therefore:

```text
fib(2) = 1 + 0 = 1

fib(3) = 1 + 1 = 2

fib(4) = 2 + 1 = 3
```

So:

```text
fib(4) = 3
```

---

## C++ Solution

```cpp
class Solution {
public:
    int fib(int n) {

        // Base case
        if (n == 0 || n == 1) {
            return n;
        }

        // Recursive calls
        int firstLast = fib(n - 1);
        int secondLast = fib(n - 2);

        // Combine results
        int ans = firstLast + secondLast;

        return ans;
    }
};
```

---

## Important Observation

This recursive solution calculates the same values multiple times.

For example:

```text
fib(5)
```

requires:

```text
fib(4)
fib(3)
```

But `fib(3)` is calculated again inside `fib(4)`.

This creates a lot of repeated work.

For example:

```text
fib(5)
       /      \
    fib(4)   fib(3)
     /  \     /  \
 fib(3) fib(2) ...
```

Notice that `fib(3)` appears multiple times.

This is why the simple recursive solution becomes slow for larger values of `n`.

---

## Complexity Analysis

### Time Complexity

The recursive tree grows exponentially.

```text
O(2^n)
```

---

### Space Complexity

The maximum depth of the recursion is `n`.

Therefore, the recursion stack requires:

```text
O(n)
```

---

## Key Takeaways

* Fibonacci is a classic example of recursion.
* Every recursive solution needs a **base case**.
* The recursive case breaks `fib(n)` into `fib(n-1)` and `fib(n-2)`.
* Recursive calls continue until `n` becomes `0` or `1`.
* The recursive solution has significant **repeated calculations**.
* Time complexity is `O(2^n)`.
* Space complexity is `O(n)` because of the recursion call stack.
* This problem is useful for understanding **base cases, recursive cases, call stacks, and recursion trees**.
