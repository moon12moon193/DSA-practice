# LeetCode 567 - Permutation in String

## Problem

Given two strings `s1` and `s2`, check if `s2` contains a permutation of `s1`.

A permutation of `s1` means the characters should appear with the same frequency, but the order can be different.

Example:


s1 = "ab"
s2 = "eidbaooo"

Output: true

Explanation:
"ba" is a permutation of "ab"




## Approach

This solution uses the **Fixed Size Sliding Window** technique.

### Idea

* A permutation of `s1` must have the same length as `s1`.
* Create a frequency array for characters of `s1`.
* Maintain a window in `s2` with the same size as `s1`.
* Compare the character frequencies of the current window with `s1`.
* Slide the window one character at a time:

  * Remove the left character.
  * Add the new right character.
  * Check if both frequency arrays are equal.

---

## Algorithm

1. If `s1` is larger than `s2`, return `false`.
2. Store character frequencies of `s1` in an array of size 26.
3. Create the first window of size `s1.length()` in `s2`.
4. Compare the two frequency arrays.
5. Slide the window:

   * decrease frequency of outgoing character
   * increase frequency of incoming character
   * compare arrays
6. If any window matches, return `true`.

---

## Complexity Analysis

### Time Complexity


O(26 * n)


Because each window comparison checks 26 characters.

### Space Complexity


O(1)


Only two fixed arrays of size 26 are used.

---

## Pattern Used


Array
+
Frequency Counting
+
Fixed Sliding Window


This pattern is useful for problems involving:

* permutations
* anagrams
* substring matching
* fixed length windows
