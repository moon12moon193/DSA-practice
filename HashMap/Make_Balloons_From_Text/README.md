# Maximum Number of Balloons (LeetCode 1189)

## Problem

Given a string `text`, return the **maximum number of instances** of the word `"balloon"` that can be formed using the characters from `text`.

Each character in `text` can be used **only once**.

---

## Example 1

**Input**

```cpp
text = "nlaebolko"
```

**Output**

```cpp
1
```

### Explanation

The characters can form the word:

```
balloon
```

exactly one time.

---

## Example 2

**Input**

```cpp
text = "loonbalxballpoon"
```

**Output**

```cpp
2
```

### Explanation

The characters are sufficient to form:

```
balloon
balloon
```

---

## Example 3

**Input**

```cpp
text = "leetcode"
```

**Output**

```cpp
0
```

### Explanation

The required characters are not available to form `"balloon"`.

---

# Intuition

To build the word `"balloon"`, we need a specific number of each character:

| Character | Required Count |
|-----------|---------------:|
| b | 1 |
| a | 1 |
| l | 2 |
| o | 2 |
| n | 1 |

The idea is to:

1. Count the frequency of every character in `"balloon"`.
2. Count the frequency of every character in `text`.
3. For each required character, determine how many complete copies it can contribute.
4. The smallest value among all required characters is the maximum number of `"balloon"` words that can be formed.

---

# Approach

## Step 1: Count Required Characters

Create a hash map for the word `"balloon"`.

```cpp
unordered_map<char, int> balloon;
```

Traverse the word.

```cpp
balloon[makeVal[i]]++;
```

The map becomes:

| Character | Frequency |
|-----------|----------:|
| b | 1 |
| a | 1 |
| l | 2 |
| o | 2 |
| n | 1 |

---

## Step 2: Count Characters in the Text

Create another hash map.

```cpp
unordered_map<char, int> textMap;
```

Traverse the input string.

```cpp
textMap[text[j]]++;
```

This stores the frequency of every character in `text`.

---

## Step 3: Calculate Possible Copies

For every required character,

calculate

```cpp
available / required
```

Example

```
Available 'l' = 6

Required 'l' = 2

Copies = 6 / 2 = 3
```

Repeat this for every required character.

---

## Step 4: Find the Minimum

The character that can form the **fewest copies** limits the answer.

```cpp
res = min(res, copies);
```

If any required character is missing,

return

```cpp
0
```

---

# Dry Run

### Input

```text
text = "loonbalxballpoon"
```

---

### Frequency in `"balloon"`

| Character | Required |
|-----------|---------:|
| b | 1 |
| a | 1 |
| l | 2 |
| o | 2 |
| n | 1 |

---

### Frequency in `text`

| Character | Available |
|-----------|----------:|
| b | 2 |
| a | 2 |
| l | 4 |
| o | 4 |
| n | 2 |

---

### Possible Copies

| Character | Available | Required | Copies |
|-----------|----------:|---------:|-------:|
| b | 2 | 1 | 2 |
| a | 2 | 1 | 2 |
| l | 4 | 2 | 2 |
| o | 4 | 2 | 2 |
| n | 2 | 1 | 2 |

Minimum value

```
2
```

Final answer

```text
2
```

---

# Another Example

### Input

```text
text = "leetcode"
```

Character frequencies

| Character | Available | Required |
|-----------|----------:|---------:|
| b | 0 | 1 |
| a | 0 | 1 |
| l | 1 | 2 |
| o | 1 | 2 |
| n | 0 | 1 |

Several required characters are missing.

Return

```text
0
```

---

# Why Divide the Frequencies?

Some characters appear more than once in `"balloon"`.

For example,

```
balloon
```

contains

```
l → 2

o → 2
```

If the input contains

```
6 l's
```

then

```
6 / 2 = 3
```

meaning only **3 complete words** can use those characters.

This is why integer division is necessary.

---

# Complexity Analysis

### Time Complexity

- Count characters in `"balloon"`: **O(1)** (constant length)
- Count characters in `text`: **O(n)**
- Compare frequencies: **O(1)** (only five distinct required characters)

Overall:

```text
O(n)
```

where `n` is the length of `text`.

---

### Space Complexity

Two hash maps are used.

Since the number of distinct characters is bounded by the alphabet size, the extra space is:

```text
O(1)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> textMap;
        unordered_map<char, int> balloon;

        string makeVal = "balloon";

        int res = INT_MAX;

        for (int i = 0; i < makeVal.length(); i++) {
            balloon[makeVal[i]]++;
        }

        for (int j = 0; j < text.length(); j++) {
            textMap[text[j]]++;
        }

        for (auto entry : balloon) {

            char ch = entry.first;
            int required = entry.second;
            int available = textMap[ch];

            if (available < required) {
                return 0;
            }

            res = min(res, available / required);
        }

        return res;
    }
};
```

---

# Key Takeaways

- Use **Hash Maps** to count character frequencies in both the target word and the input string.
- Some characters in `"balloon"` appear multiple times, so use **integer division** (`available / required`) to determine how many complete words each character can support.
- The **minimum** number of possible copies among all required characters is the final answer.
- If any required character is missing or insufficient, return `0`.
- The solution runs in **O(n)** time with **O(1)** extra space.
