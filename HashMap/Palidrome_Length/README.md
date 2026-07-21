# Longest Palindrome (LeetCode 409)

## Problem

Given a string `s` consisting of uppercase and lowercase English letters, return the **length of the longest palindrome** that can be built using those letters.

You do **not** have to use all the characters.

---

## Example 1

**Input**

```cpp
s = "abccccdd"
```

**Output**

```cpp
7
```

### Explanation

One possible palindrome is:

```text
dccaccd
```

Its length is `7`.

---

## Example 2

**Input**

```cpp
s = "a"
```

**Output**

```cpp
1
```

---

## Example 3

**Input**

```cpp
s = "bb"
```

**Output**

```cpp
2
```

---

# Intuition

A palindrome reads the same from left to right and right to left.

To build a palindrome:

- Characters with **even frequencies** can be used completely.
- Characters with **odd frequencies** can contribute all but one of their occurrences.
- If at least one character has an odd frequency, **one remaining character** can be placed in the center of the palindrome.

A **Hash Map** is used to count the frequency of each character.

---

# Approach

## Step 1: Count Character Frequencies

Create a hash map.

```cpp
unordered_map<char, int> f;
```

Traverse the string and count the frequency of each character.

```cpp
f[s[i]]++;
```

---

## Step 2: Process Each Frequency

Traverse every key-value pair in the hash map.

### Case 1: Even Frequency

If the frequency is even,

use all occurrences.

```cpp
ans += val;
```

---

### Case 2: Odd Frequency

If the frequency is odd,

one character must remain unused.

So,

```cpp
ans += val - 1;
```

Mark that one character is still available.

```cpp
f[key] = 1;
```

---

## Step 3: Check for a Center Character

Traverse the hash map again.

If any character has value

```cpp
1
```

it can be placed at the center.

Return

```cpp
ans + 1;
```

Otherwise,

return

```cpp
ans;
```

---

# Dry Run

### Input

```text
s = "abccccdd"
```

---

### Frequency Map

| Character | Frequency |
|-----------|----------:|
| a | 1 |
| b | 1 |
| c | 4 |
| d | 2 |

---

### Process Frequencies

| Character | Frequency | Contribution |
|-----------|----------:|-------------:|
| a | 1 | 0 |
| b | 1 | 0 |
| c | 4 | 4 |
| d | 2 | 2 |

Current length

```text
6
```

Since there are odd-frequency characters (`a` and `b`),

one of them can be placed in the center.

Final answer

```text
6 + 1 = 7
```

---

# Another Example

### Input

```text
s = "ccc"
```

Frequency

| Character | Frequency |
|-----------|----------:|
| c | 3 |

Contribution

```text
3 - 1 = 2
```

One character remains.

Place it in the center.

Final answer

```text
3
```

---

# Why Can Only One Odd Character Be in the Center?

A palindrome is symmetric.

Every character must appear in pairs:

```text
a b c | c b a
```

Only the **middle position** does not require a matching pair.

Therefore,

only **one** character with an odd remaining frequency can occupy the center.

---

# Complexity Analysis

### Time Complexity

- Build frequency map: **O(n)**
- Traverse the hash map twice: **O(k)**

Overall:

```text
O(n)
```

where:

- `n` = length of the string
- `k` = number of distinct characters

---

### Space Complexity

The hash map stores character frequencies.

```text
O(k)
```

For English letters, this is effectively **O(1)** because the number of possible characters is bounded.

---

# C++ Solution

```cpp
class Solution {
public:
    int longestPalindrome(string s) {

        int ans = 0;

        unordered_map<char, int> f;

        for (int i = 0; i < s.length(); i++) {
            f[s[i]]++;
        }

        for (auto entry : f) {

            char key = entry.first;
            int val = entry.second;

            if (val % 2 == 0) {

                ans += val;
                f[key] = 0;

            } else {

                ans += val - 1;
                f[key] = 1;
            }
        }

        for (auto entry : f) {

            if (entry.second == 1) {
                return ans + 1;
            }
        }

        return ans;
    }
};
```

---

# Key Takeaways

- Use a **Hash Map** to count the frequency of each character.
- Add all **even frequencies** directly to the answer.
- For **odd frequencies**, add `frequency - 1`, leaving one character unused.
- If at least one odd-frequency character exists, place one of the remaining characters in the center by adding `1` to the answer.
- The solution runs in **O(n)** time with **O(k)** extra space, where `k` is the number of distinct characters.
