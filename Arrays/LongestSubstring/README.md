

# Longest Substring Without Repeating Characters

## Problem Description

Given a string `s`, find the length of the **longest substring** that contains no repeating characters.

A substring is a continuous part of a string.

### Example 1

Input:


s = "abcabcbb"


Substrings without repeating characters:


abc
bca
cab


The longest length is:



3



Output:


3


### Example 2

Input:


s = "bbbbb"



The longest substring without repeating characters is:



b



Output:


1





## Approach

This solution uses the **Sliding Window technique** with a **Hash Map**.

### Idea:

Maintain a window using two pointers:

- `low` → starting index of current window
- `high` → ending index of current window

The hashmap stores:


character -> frequency


For every new character:

1. Add the character to the hashmap.
2. Check if the window contains duplicate characters.
3. If duplicates exist:
   - Move `low` forward.
   - Remove characters from the hashmap.
4. When the window becomes valid, update the maximum length.

---



## Dry Run

Input:

s = "pwwkew"


Window movement:

| Window | Valid?         | Length     |
| ------ | -------------- | ---------- |
| p      | Yes            | 1          |
| pw     | Yes            | 2          |
| pww    | No (w repeats) | remove p,w |
| w      | Yes            | 1          |
| wk     | Yes            | 2          |
| wke    | Yes            | 3          |
| kew    | Yes            | 3          |

Answer:


3




## Complexity Analysis

### Time Complexity

Each character is added and removed from the window at most once.

Therefore:


O(n)


---

### Space Complexity

The hashmap stores at most all unique characters.

Therefore:


O(n)


---

## Concepts Used

* Sliding Window
* Two Pointer Technique
* Hash Map
* Frequency Counting

---

## Language

C++

