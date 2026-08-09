# Recursion & Backtracking — Generating Valid Combinations

## Problem

Given an integer `n`, generate all possible combinations of `n` pairs of parentheses such that every generated sequence is **valid**.

A valid sequence must satisfy:

* The number of opening parentheses `(` must never be less than the number of closing parentheses `)` at any point.
* Exactly `n` opening parentheses must be used.
* Exactly `n` closing parentheses must be used.

---

## Approach

This solution uses **Recursion + Backtracking**.

At every step, there are at most two choices:

```text
1. Add '('
2. Add ')'
```

But a closing parenthesis can only be added when:

```text
close < open
```

This prevents invalid sequences from being generated.

---

# Important Variables

The recursive function is:

```cpp
fun(open, close, n, temp, result)
```

Each parameter has a specific purpose.

### `open`

Number of opening parentheses used so far.

### `close`

Number of closing parentheses used so far.

### `n`

Total number of opening and closing parentheses required.

### `temp`

Current combination being constructed.

### `result`

Stores all valid combinations.

---

# Base Case

The recursion stops when both the opening and closing parentheses have reached `n`.

```cpp
if (open == n && close == n) {
    result.push_back(temp);
    return;
}
```

For example, when:

```text
n = 2
```

and:

```text
temp = "(())"
open = 2
close = 2
```

the combination is complete, so it is added to the result.

---

# Choice 1 — Add Opening Parenthesis

We can add `(` as long as we haven't used all `n` opening parentheses.

```cpp
if (open < n) {
    temp.push_back('(');

    fun(open + 1, close, n, temp, result);

    temp.pop_back();
}
```

There are two important operations here:

### Make the Choice

```cpp
temp.push_back('(');
```

### Explore

```cpp
fun(open + 1, close, n, temp, result);
```

### Undo the Choice

```cpp
temp.pop_back();
```

The `pop_back()` is the **backtracking step**.

---

# Choice 2 — Add Closing Parenthesis

A closing parenthesis can only be added when:

```cpp
close < open
```

```cpp
if (close < open) {
    temp.push_back(')');

    fun(open, close + 1, n, temp, result);

    temp.pop_back();
}
```

Why?

Consider:

```text
")("
```

This is invalid because a closing parenthesis appears before any opening parenthesis.

Therefore, we never allow:

```text
close > open
```

---

# Why `close < open`?

Suppose:

```text
open = 2
close = 1
```

Current sequence could be:

```text
(())
```

There is one unmatched opening parenthesis, so adding `)` is valid.

But if:

```text
open = 1
close = 1
```

there are no unmatched opening parentheses.

We cannot add another `)`.

Therefore:

```cpp
close < open
```

guarantees that we never create an invalid prefix.

---

# Backtracking Pattern

This solution follows the fundamental backtracking pattern:

```text
Make Choice
     ↓
Explore
     ↓
Undo Choice
```

For example:

```cpp
temp.push_back('(');      // Make choice

fun(...);                 // Explore

temp.pop_back();          // Undo choice
```

The same pattern is used when adding `)`.

---

# Recursion Tree

For:

```text
n = 2
```

the recursion starts with:

```text
""
```

Then:

```text
                 ""
                 |
                 (
              /     \
            ((       ()
            |         |
           (()       ()
            |         |
           (())      ()(
                       |
                      ())
```

The valid results are:

```text
(())
()()
```

Invalid branches are never generated because of:

```cpp
if (close < open)
```

---

# Dry Run

Consider:

```text
n = 2
```

Initially:

```text
open = 0
close = 0
temp = ""
```

---

### Step 1

`open < n`

Add:

```text
(
```

Now:

```text
open = 1
close = 0
temp = "("
```

---

### Step 2

We can add another `(`:

```text
((
```

Now:

```text
open = 2
close = 0
```

---

### Step 3

Cannot add another `(` because:

```text
open == n
```

But:

```text
close < open
```

so add:

```text
(
(
)
```

Now:

```text
temp = "(()"
open = 2
close = 1
```

---

### Step 4

Add the final `)`:

```text
(())
```

Now:

```text
open = 2
close = 2
```

Base case is reached.

Store:

```text
(())
```

---

### Backtracking

The last `)` is removed:

```cpp
temp.pop_back();
```

Then the recursion goes back and explores other available choices.

Eventually:

```text
()()
```

is generated as well.

---

# C++ Solution

```cpp
class Solution {
public:

    void fun(int open,
             int close,
             int n,
             string& temp,
             vector<string>& result) {

        // Base case
        if (open == n && close == n) {
            result.push_back(temp);
            return;
        }

        // Choice 1: Add opening parenthesis
        if (open < n) {

            temp.push_back('(');

            fun(open + 1,
                close,
                n,
                temp,
                result);

            // Backtrack
            temp.pop_back();
        }

        // Choice 2: Add closing parenthesis
        if (close < open) {

            temp.push_back(')');

            fun(open,
                close + 1,
                n,
                temp,
                result);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string temp;

        fun(0, 0, n, temp, result);

        return result;
    }
};
```

---

# Complexity Analysis

The number of valid combinations is given by the **Catalan numbers**.

The number of valid sequences is:

```text
C(n) = 1/(n+1) × (2n choose n)
```

Therefore, the number of generated results grows very quickly as `n` increases.

The overall complexity is commonly expressed in terms of the number of generated combinations and their length.

Since every valid string has length:

```text
2n
```

the output itself requires:

```text
O(n × C(n))
```

space.

The recursion stack has maximum depth:

```text
O(n)
```

---

# Important Concepts Learned

### 1. Recursion

The function calls itself with updated values:

```cpp
fun(open + 1, close, ...);
```

or:

```cpp
fun(open, close + 1, ...);
```

---

### 2. Base Case

Stops recursion when a complete valid sequence is created:

```cpp
open == n && close == n
```

---

### 3. Backtracking

Undo the previous choice:

```cpp
temp.pop_back();
```

This allows the same `temp` string to be reused for different branches.

---

### 4. Constraint Checking

Before adding `)`:

```cpp
close < open
```

This prevents invalid combinations from being explored.

---

### 5. Pruning

Invalid branches are avoided before they are created.

Instead of generating something like:

```text
)(
```

the condition prevents the invalid `)` from being added at the beginning.

---

# Key Takeaways

* Recursion explores different possible states.
* Backtracking means **choose → explore → undo**.
* `open` tracks how many `(` have been used.
* `close` tracks how many `)` have been used.
* `open < n` controls when `(` can be added.
* `close < open` ensures that `)` never creates an invalid sequence.
* The base case stores a completed valid sequence.
* `pop_back()` restores the previous state so another branch can be explored.
* This is an excellent example of combining **recursion, backtracking, constraints, and pruning**.
