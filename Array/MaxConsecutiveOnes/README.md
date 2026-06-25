# Max Consecutive Ones III

## Problem Description

Given a binary array `nums` and an integer `k`, find the maximum number of consecutive `1`s in the array if you can flip at most `k` zeros.

A zero can be changed into a one, and the goal is to find the longest possible subarray containing at most `k` zeros.

## Approach

This solution uses the **Sliding Window (Two Pointer)** technique.

The idea:

* Maintain a window using two pointers:

  * `low` → starting index of the current window
  * `high` → ending index of the current window
* Store the count of `0`s and `1`s using a frequency array.
* Expand the window using `high`.
* If the number of zeros in the current window becomes greater than `k`, shrink the window from the left using `low`.

## Algorithm Steps

1. Initialize:

   * `low = 0`
   * `high = 0`
   * frequency array of size 2
   * `result` to store maximum length

2. Traverse the array:

   * Add the current element to the frequency array.

3. Calculate current window length:


length = high - low + 1


4. Calculate the number of zeros in the current window:


zeros = window length - number of ones


5. If:


zeros > k


shrink the window:

* remove the element at `low`
* move `low` forward

6. Update the maximum length.

7. Return the result.

## Example

Input:


nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2


Output:


6


Explanation:

The longest valid window contains at most 2 zeros after flipping them.

## Complexity Analysis

### Time Complexity


O(n)


Each element is visited by `high` once and removed by `low` at most once.

### Space Complexity


O(1)


Only a fixed-size array of size 2 is used.

## Implementation Details

The array:


int arr[2] = {0};


stores:


arr[0] → count of zeros
arr[1] → count of ones

Indexing works because:


0 → index 0
1 → index 1


## Language

C++

## Concepts Used

* Sliding Window
* Two Pointers
* Frequency Counting
* Array Manipulation
* Greedy Window Expansion
