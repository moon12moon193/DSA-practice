# Remove All Adjacent Duplicates in String II (LeetCode 1209)

## Problem

Given a string `s` and an integer `k`, repeatedly remove groups of **`k` adjacent identical characters** until no such group remains.

Return the final string after all possible removals.

---

## Example 1

**Input**

```cpp
s = "abcd"
k = 2
```

**Output**

```cpp
"abcd"
```

### Explanation

No group of 2 adjacent identical characters exists.

---

## Example 2

**Input**

```cpp
s = "deeedbbcccbdaa"
k = 3
```

**Output**

```cpp
"aa"
```

### Explanation

```
deeedbbcccbdaa

Remove "eee"

ddbbcccbdaa

Remove "ccc"

ddbbbdaa

Remove "bbb"

dddaa

Remove "ddd"

aa
```

---

## Example 3

**Input**

```cpp
s = "pbbcggttciiippooaais"
k = 2
```

**Output**

```cpp
"ps"
```

---

# Intuition

Whenever `k` identical adjacent characters appear together, they should be removed immediately.

A **stack** is ideal because it keeps track of the **most recently processed character**.

Instead of storing only characters, store:

- the character
- the number of consecutive occurrences of that character

This allows us to know exactly when a group reaches size `k`.

---

# Approach

## Step 1: Create a Stack

Each element of the stack stores:

```cpp
pair<char, int>
```

where

- `first` → character
- `second` → frequency of consecutive occurrences

Example

```
('a',3)
```

means

```
aaa
```

---

## Step 2: Traverse the String

Process every character one by one.

### Case 1: Stack is Empty

Push the current character with frequency 1.

```cpp
s.push({st[i], 1});
```

---

### Case 2: Current Character is Different

Start a new group.

```cpp
s.push({st[i], 1});
```

---

### Case 3: Same Character

If the current character matches the top character,

increase its frequency.

```cpp
s.top().second++;
```

---

### Case 4: Frequency Reaches `k`

When the frequency becomes `k`,

remove the entire group.

```cpp
s.pop();
```

This automatically allows previously separated groups to become adjacent.

---

## Step 3: Build the Answer

Each stack element contains

- a character
- its remaining frequency

Append the character exactly `frequency` times.

```cpp
while (s.top().second > 0) {

    res += s.top().first;

    s.top().second--;
}
```

Since the stack returns characters in reverse order,

reverse the final string.

---

# Dry Run

### Input

```
s = "deeedbbcccbdaa"

k = 3
```

---

### Processing

```
d
```

Stack

```
(d,1)
```

---

```
e
```

Stack

```
(d,1)
(e,1)
```

---

```
e
```

Stack

```
(d,1)
(e,2)
```

---

```
e
```

Frequency becomes 3.

Remove

```
(e,3)
```

Stack

```
(d,1)
```

Continue processing the remaining characters in the same way.

Final result

```
aa
```

---

# Why Store Frequency?

Suppose

```
aaab
```

and

```
k = 3
```

Without storing the count,

you would need to repeatedly scan backward to know how many consecutive characters exist.

By storing

```
(a,3)
```

you immediately know that the group should be removed.

This makes the solution efficient.

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
    string removeDuplicates(string st, int k) {

        stack<pair<char, int>> s;

        string res = "";

        for (int i = 0; i < st.length(); i++) {

            if (s.empty()) {

                s.push({st[i], 1});

            } else {

                if (st[i] != s.top().first) {

                    s.push({st[i], 1});

                } else {

                    if (s.top().second == k - 1) {

                        s.pop();

                    } else {

                        s.top().second++;

                    }
                }
            }
        }

        while (!s.empty()) {

            while (s.top().second > 0) {

                res += s.top().first;

                s.top().second--;

            }

            s.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
```

---

# Key Takeaways

- Use a **stack of `(character, frequency)` pairs** to efficiently track consecutive characters.
- Increment the frequency when the current character matches the top of the stack.
- Remove a group immediately when its frequency reaches `k`.
- After processing the string, reconstruct the answer from the remaining stack contents.
- Reverse the result because characters are extracted from the stack in reverse order.
- Each character is processed at most once, resulting in an **O(n)** time solution with **O(n)** extra space.
