


# Count Good Substrings

## Problem Description

Given a string `s`, count the number of **good substrings** of length `3`.

A substring is called **good** if all three characters in the substring are **distinct**.

### Example:

Input:


s = "xyzzaz"



Substrings of length 3:



xyz → good (x, y, z are different)
yzz → not good (z repeats)
zza → not good (z repeats)
zaz → not good (z repeats)



Output:


1





## Approach

This solution uses a **sliding window technique**.

- Maintain two pointers:
  - `low` → starting index of current substring
  - `high` → ending index of current substring

- Since we need substrings of length `3`, initialize:


low = 0
high = 2


* For every window:

  1. Create a hash map to store character frequencies.
  2. Insert the 3 characters into the hash map.
  3. If the hashmap size is `3`, all characters are unique, so increment the answer.
  4. Move the window forward.

---



---

## Dry Run

Input:


s = "aababc"


Windows:

| Substring | Frequency Map | Good? |
| --------- | ------------- | ----- |
| aab       | a:2, b:1      | No    |
| aba       | a:2, b:1      | No    |
| bab       | b:2, a:1      | No    |
| abc       | a:1, b:1, c:1 | Yes   |

Answer:


1


---

## Complexity Analysis

### Time Complexity

The loop runs `n-2` times.

For every window, only 3 characters are checked.

Therefore:


O(n)


### Space Complexity

The hashmap stores at most 3 characters because the window size is fixed.

Therefore:


O(1)


---

## Concepts Used

* Sliding Window
* Hash Map (`unordered_map`)
* Frequency Counting
* Two Pointer Technique

---

## Language

C++







