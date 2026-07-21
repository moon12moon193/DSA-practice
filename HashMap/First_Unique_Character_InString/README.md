# First Unique Character in a String (LeetCode 387)

## Problem

Given a string `s`, return the **index of the first non-repeating character**.

If every character appears more than once, return `-1`.

---

## Example 1

**Input**

```cpp
s = "leetcode"
```

**Output**

```cpp
0
```

### Explanation

- `'l'` appears only once.
- It is the first unique character.
- Therefore, return its index `0`.

---

## Example 2

**Input**

```cpp
s = "loveleetcode"
```

**Output**

```cpp
2
```

### Explanation

Character frequencies:

```
l → 2
o → 2
v → 1
e → 4
t → 1
c → 1
d → 1
```

The first character with frequency `1` is `'v'` at index `2`.

---

## Example 3

**Input**

```cpp
s = "aabb"
```

**Output**

```cpp
-1
```

### Explanation

Every character appears more than once, so there is no unique character.

---

# Intuition

To determine whether a character is unique, we first need to know **how many times each character appears**.

A **Hash Map** is ideal for this because it stores the frequency of every character in **constant average time**.

The solution uses **two passes**:

1. Count the frequency of each character.
2. Traverse the string again to find the first character whose frequency is `1`.

---

# Approach

## Step 1: Count Character Frequencies

Create a hash map to store the frequency of each character.

```cpp
unordered_map<char, int> f;
```

Traverse the string and increment the count.

```cpp
for (int i = 0; i < s.length(); i++) {
    f[s[i]]++;
}
```

---

## Step 2: Find the First Unique Character

Traverse the string again from left to right.

If the frequency of the current character is `1`, return its index.

```cpp
if (f[s[i]] == 1) {
    return i;
}
```

---

## Step 3: No Unique Character

If no character has a frequency of `1`, return

```cpp
-1
```

---

# Dry Run

### Input

```
s = "loveleetcode"
```

### First Pass (Frequency Count)

| Character | Frequency |
|-----------|----------:|
| l | 2 |
| o | 2 |
| v | 1 |
| e | 4 |
| t | 1 |
| c | 1 |
| d | 1 |

---

### Second Pass

| Index | Character | Frequency | Action |
|------:|-----------|----------:|--------|
| 0 | l | 2 | Continue |
| 1 | o | 2 | Continue |
| 2 | v | 1 | Return 2 |

Final answer

```
2
```

---

# Why Two Traversals?

Suppose

```
s = "leetcode"
```

When reading the first character `'l'`, we cannot immediately determine whether it is unique because the same character might appear later in the string.

Therefore:

- **First traversal** → Count frequencies.
- **Second traversal** → Identify the first character with frequency `1`.

This guarantees the correct answer.

---

# Complexity Analysis

### Time Complexity

- First traversal: **O(n)**
- Second traversal: **O(n)**

Overall:

```
O(n)
```

where `n` is the length of the string.

---

### Space Complexity

The hash map stores the frequency of each distinct character.

```
O(k)
```

where `k` is the number of unique characters.

For lowercase English letters, this is effectively **O(1)** since there are at most 26 possible characters.

---

# C++ Solution

```cpp
class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> f;

        for (int i = 0; i < s.length(); i++) {
            f[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (f[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

---

# Key Takeaways

- Use a **Hash Map** to efficiently count the frequency of each character.
- Perform **two traversals**:
  - First to build the frequency map.
  - Second to find the first character with frequency `1`.
- A hash map provides **O(1)** average-time access for updating and retrieving frequencies.
- The overall solution runs in **O(n)** time with **O(k)** extra space, where `k` is the number of distinct characters.
