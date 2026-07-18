# Remove All Adjacent Duplicates in String (LeetCode 1047)

## Problem

Given a string `s`, repeatedly remove adjacent duplicate characters until no adjacent duplicates remain.

Return the final string after all possible removals.

---

## Example 1

**Input**

```cpp
s = "abbaca"
```

**Output**

```cpp
"ca"
```

### Explanation

```
abbaca
  ^^

Remove "bb"

aaca
^^

Remove "aa"

ca
```

No more adjacent duplicates remain.

---

## Example 2

**Input**

```cpp
s = "azxxzy"
```

**Output**

```cpp
"ay"
```

### Explanation

```
azxxzy

Remove "xx"

azzy

Remove "zz"

ay
```

---

# Intuition

Whenever two **adjacent characters** are the same, they should be removed.

A **stack** is perfect for this because it always keeps track of the most recently processed character.

For each character:

- If it is different from the top of the stack, push it.
- If it is the same as the top of the stack, pop the top instead of pushing the current character.

This automatically removes adjacent duplicates and also handles new duplicates formed after previous removals.

---

# Approach

## Step 1: Create an Empty Stack

The stack stores characters that remain after processing.

```cpp
stack<char> s;
```

---

## Step 2: Traverse the String

Process each character one by one.

### Case 1: Stack is Empty

Push the current character.

```cpp
s.push(str[i]);
```

---

### Case 2: Top Character Matches

If

```cpp
s.top() == str[i]
```

remove the duplicate by popping.

```cpp
s.pop();
```

---

### Case 3: Characters are Different

Push the current character.

```cpp
s.push(str[i]);
```

---

## Step 3: Build the Answer

The stack stores the answer in reverse order.

Pop every character and append it to the result string.

```cpp
while (!s.empty()) {

    res += s.top();

    s.pop();
}
```

---

## Step 4: Reverse the Result

Since the stack gives characters from last to first,

reverse the string.

```cpp
reverse(res.begin(), res.end());
```

Return the result.

---

# Dry Run

### Input

```
abbaca
```

---

### Process Each Character

| Character | Stack |
|-----------|-------|
| a | a |
| b | ab |
| b | a |
| a | empty |
| c | c |
| a | ca |

---

### Build Result

Pop from stack

```
a
```

then

```
c
```

Result before reversing

```
ac
```

Reverse

```
ca
```

Final answer

```
ca
```

---

# Another Dry Run

### Input

```
azxxzy
```

| Character | Stack |
|-----------|-------|
| a | a |
| z | az |
| x | azx |
| x | az |
| z | a |
| y | ay |

Final answer

```
ay
```

---

# Why Does the Stack Work?

Suppose

```
abbaca
```

After removing

```
bb
```

the string becomes

```
aaca
```

Now another duplicate

```
aa
```

appears.

The stack naturally handles this because after popping `b`, the previous `a` is again on the top of the stack.

When the next `a` is processed, they become adjacent and are removed.

No extra traversal is needed.

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

The stack may store all characters in the worst case.

```
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    string removeDuplicates(string str) {

        string res = "";
        stack<char> s;

        for (int i = 0; i < str.length(); i++) {

            if (s.empty()) {

                s.push(str[i]);

            } else {

                if (s.top() == str[i]) {

                    s.pop();

                } else {

                    s.push(str[i]);
                }
            }
        }

        while (!s.empty()) {

            char c = s.top();

            res += c;

            s.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
```

---

# Key Takeaways

- A **stack** is ideal for removing adjacent duplicates because it always gives access to the most recently processed character.
- If the current character matches the top of the stack, remove the duplicate by popping.
- Otherwise, push the current character onto the stack.
- Build the answer by popping all characters from the stack and reversing the result.
- Each character is processed at most twice (one push and one pop), giving an efficient **O(n)** time complexity.
