# Ransom Note (LeetCode 383)

## Problem

Given two strings:

- `ransomNote`
- `magazine`

Return `true` if the `ransomNote` can be constructed using the characters from `magazine`; otherwise, return `false`.

Each character in `magazine` can be used **only once**.

---

## Example 1

**Input**

```cpp
ransomNote = "a"
magazine = "b"
```

**Output**

```cpp
false
```

### Explanation

The character `'a'` is not available in `magazine`.

---

## Example 2

**Input**

```cpp
ransomNote = "aa"
magazine = "ab"
```

**Output**

```cpp
false
```

### Explanation

The magazine contains only one `'a'`, but the ransom note requires two.

---

## Example 3

**Input**

```cpp
ransomNote = "aa"
magazine = "aab"
```

**Output**

```cpp
true
```

### Explanation

The magazine contains two `'a'` characters, so the ransom note can be constructed.

---

# Intuition

To determine whether the ransom note can be formed, we need to know **how many times each character appears** in both strings.

A **Hash Map** is ideal for counting character frequencies.

The idea is simple:

- Count the frequency of every character in the ransom note.
- Count the frequency of every character in the magazine.
- Compare the frequencies.
- If the magazine contains fewer occurrences of any required character, constructing the ransom note is impossible.

---

# Approach

## Step 1: Count Frequencies in the Ransom Note

Create a hash map to store the frequency of each character.

```cpp
unordered_map<char, int> ransom;
```

Traverse the ransom note.

```cpp
ransom[ransomNote[i]]++;
```

---

## Step 2: Count Frequencies in the Magazine

Create another hash map.

```cpp
unordered_map<char, int> magazineMap;
```

Traverse the magazine.

```cpp
magazineMap[magazine[j]]++;
```

---

## Step 3: Compare Frequencies

Traverse every character stored in the ransom note.

For each character,

compare its required frequency with the available frequency in the magazine.

```cpp
if (magazineVal < ransomVal)
    return false;
```

If every required character is available in sufficient quantity,

return

```cpp
true
```

---

# Dry Run

### Input

```text
ransomNote = "aa"
magazine   = "aab"
```

---

### Frequency Maps

#### Ransom Note

| Character | Frequency |
|-----------|----------:|
| a | 2 |

---

#### Magazine

| Character | Frequency |
|-----------|----------:|
| a | 2 |
| b | 1 |

---

### Compare

| Character | Needed | Available | Result |
|-----------|-------:|----------:|--------|
| a | 2 | 2 | ✔ Enough |

All required characters are available.

Final answer

```text
true
```

---

# Another Example

### Input

```text
ransomNote = "aa"
magazine   = "ab"
```

---

### Frequency Maps

#### Ransom Note

| Character | Frequency |
|-----------|----------:|
| a | 2 |

#### Magazine

| Character | Frequency |
|-----------|----------:|
| a | 1 |
| b | 1 |

Comparison

```text
Needed : 2
Available : 1
```

Since

```
1 < 2
```

return

```text
false
```

---

# Why Use a Hash Map?

Without a hash map,

for every character in the ransom note, we would have to repeatedly search the magazine.

This could lead to an **O(n × m)** solution.

A hash map stores character frequencies, allowing constant average-time lookups.

This reduces the overall complexity to linear time.

---

# Complexity Analysis

### Time Complexity

- Count frequencies in the ransom note: **O(n)**
- Count frequencies in the magazine: **O(m)**
- Compare frequencies: **O(k)**

Overall:

```text
O(n + m)
```

where:

- `n` = length of `ransomNote`
- `m` = length of `magazine`
- `k` = number of distinct characters in the ransom note

---

### Space Complexity

Two hash maps store character frequencies.

```text
O(k)
```

where `k` is the number of distinct characters.

For lowercase English letters, this is effectively **O(1)** because there are at most 26 possible characters.

---

# C++ Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> ransom;
        unordered_map<char, int> magazineMap;

        for (int i = 0; i < ransomNote.length(); i++) {
            ransom[ransomNote[i]]++;
        }

        for (int j = 0; j < magazine.length(); j++) {
            magazineMap[magazine[j]]++;
        }

        for (auto entry : ransom) {

            char ransomChar = entry.first;
            int required = entry.second;
            int available = magazineMap[ransomChar];

            if (available < required) {
                return false;
            }
        }

        return true;
    }
};
```

---

# Key Takeaways

- Use **Hash Maps** to count the frequency of characters in both strings.
- Compare the required frequency of each character with its available frequency.
- If any required character appears fewer times in the magazine, return `false`.
- Otherwise, return `true`.
- Hash maps provide **O(1)** average-time lookups, making the overall solution **O(n + m)**.
