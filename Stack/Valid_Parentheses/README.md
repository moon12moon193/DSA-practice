# Valid Parentheses (LeetCode 20)

## Problem

Given a string `s` containing only the characters:

- `(` and `)`
- `{` and `}`
- `[` and `]`

Determine whether the input string is **valid**.

A string is valid if:

1. Every opening bracket has a corresponding closing bracket of the same type.
2. Brackets are closed in the correct order.
3. Every closing bracket has a matching opening bracket.

Return `true` if the string is valid; otherwise, return `false`.

---

## Example 1

**Input**

```cpp
s = "()"
```

**Output**

```cpp
true
```

---

## Example 2

**Input**

```cpp
s = "()[]{}"
```

**Output**

```cpp
true
```

---

## Example 3

**Input**

```cpp
s = "(]"
```

**Output**

```cpp
false
```

---

## Example 4

**Input**

```cpp
s = "([)]"
```

**Output**

```cpp
false
```

---

## Example 5

**Input**

```cpp
s = "{[]}"
```

**Output**

```cpp
true
```

---

# Intuition

Whenever we encounter an **opening bracket**, we need to remember it until its matching closing bracket appears.

Since the **most recently opened bracket must be closed first**, a **Stack** is the perfect data structure because it follows the **LIFO (Last In, First Out)** principle.

For every character:

- If it is an opening bracket, push it onto the stack.
- If it is a closing bracket:
  - The stack must not be empty.
  - The top of the stack must contain the corresponding opening bracket.
  - If it matches, pop the opening bracket.
  - Otherwise, the string is invalid.

After processing the entire string, the stack should be empty.

---

# Approach

## Step 1: Create an Empty Stack

Use a stack to store opening brackets.

```cpp
stack<char> s;
```

---

## Step 2: Traverse the String

Process each character one by one.

### Case 1: Opening Bracket

If the current character is

```
(
{
[
```

push it onto the stack.

```cpp
s.push(str[i]);
```

---

### Case 2: Closing Bracket

Before checking the top element, verify that the stack is not empty.

```cpp
if (s.empty())
    return false;
```

If the stack is empty, there is no matching opening bracket.

---

### Case 3: Matching Brackets

Compare the current closing bracket with the opening bracket at the top of the stack.

```cpp
(
matches
)

{
matches
}

[
matches
]
```

If they match,

```cpp
s.pop();
```

Otherwise,

```cpp
return false;
```

---

## Step 3: Check Remaining Stack

After processing every character,

- If the stack is empty, every opening bracket found its matching closing bracket.
- Otherwise, some opening brackets remain unmatched.

```cpp
return s.empty();
```

---

# Dry Run

### Input

```
{[]}
```

---

### Process Each Character

| Character | Stack |
|-----------|-------|
| { | { |
| [ | { [ |
| ] | { |
| } | Empty |

Stack becomes empty.

Answer

```
true
```

---

### Another Dry Run

Input

```
([)]
```

Process

```
(
Push
```

Stack

```
(
```

Process

```
[
```

Stack

```
( [
```

Next character

```
)
```

Top of stack

```
[
```

They do not match.

Return

```
false
```

---

# Why Does a Stack Work?

Consider

```
({[]})
```

The brackets are opened in this order:

```
(
{
[
```

The first bracket that must be closed is

```
[
```

Then

```
{
```

Finally

```
(
```

This is exactly **Last In, First Out (LIFO)**, making a stack the ideal data structure for this problem.

---

# Complexity Analysis

### Time Complexity

Each character is pushed and popped at most once.

```
O(n)
```

where `n` is the length of the string.

---

### Space Complexity

In the worst case, all opening brackets are stored in the stack.

```
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    bool isValid(string str) {

        stack<char> s;

        for (int i = 0; i < str.length(); i++) {

            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {

                s.push(str[i]);

            } else {

                if (s.empty()) {

                    return false;

                } else {

                    if ((s.top() == '(' && str[i] == ')') ||
                        (s.top() == '{' && str[i] == '}') ||
                        (s.top() == '[' && str[i] == ']')) {

                        s.pop();

                    } else {

                        return false;
                    }
                }
            }
        }

        return s.empty();
    }
};
```

---

# Key Takeaways

- A **Stack** is the ideal data structure for problems involving **matching pairs**.
- Push every opening bracket onto the stack.
- For each closing bracket, verify that it matches the opening bracket at the top of the stack.
- If a mismatch occurs or the stack is empty when a closing bracket is encountered, the string is invalid.
- After processing the entire string, the stack must be empty for the string to be valid.
- This solution runs in **O(n)** time and uses **O(n)** extra space.
