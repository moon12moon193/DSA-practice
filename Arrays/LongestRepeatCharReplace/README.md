# Longest Repeating Character Replacement

## Problem Description

Given a string `s` and an integer `k`, find the length of the longest substring that can be obtained by replacing at most `k` characters so that all characters in the substring are the same.

## Approach

This solution uses the **Sliding Window** technique with a frequency array.

The idea is:

* Maintain a window using two pointers:

  * `low` → starting index of the window
  * `high` → ending index of the window
* Store the frequency of each character inside the current window.
* Find the character with the maximum frequency.
* The number of replacements needed is:


window length - maximum frequency character count


If the required replacements become greater than `k`, shrink the window from the left.

## Algorithm Steps

1. Initialize:

   * `low = 0`
   * `high = 0`
   * frequency array of size 26
   * result variable to store maximum length

2. Expand the window:

   * Add the current character frequency.
   * Calculate the current window length.
   * Find the maximum occurring character frequency.

3. Check validity:

   * If:


window length - max frequency > k


shrink the window by moving `low`.

4. Update the maximum window size.

5. Return the result.

## Complexity Analysis

### Time Complexity


O(26 * n)


For every character, the frequency array of 26 characters is checked.

Since 26 is constant:


O(n)


### Space Complexity


O(26)


The frequency array stores only lowercase alphabet counts.

## Example

Input:


s = "AABABBA"
k = 1


Output:


4


Explanation:

The substring `"AABA"` can be changed by replacing one `B` with `A`, giving four repeating characters.

## Implementation Details

* Uses a fixed array of size 26 for character frequency.
* Converts characters to lowercase before indexing:


character - 'a'


This maps:


a -> 0
b -> 1
...
z -> 25


## Language

C++

## Concepts Used

* Sliding Window
* Two Pointers
* Frequency Counting
* Greedy Approach
