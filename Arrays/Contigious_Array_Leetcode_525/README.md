# Contiguous Array (LeetCode 525)

## Problem

Given a binary array `nums`, return the length of the longest contiguous subarray containing an equal number of `0`s and `1`s.

### Example 1

Input:

nums = [0,1]


Output:

2


Explanation:

The entire array contains one `0` and one `1`.

---

### Example 2

Input:

nums = [0,1,0]


Output:

2


Explanation:

The longest subarray with equal numbers of `0`s and `1`s is `[0,1]` or `[1,0]`.

---

# Intuition

We need a fast way to determine whether a subarray has an equal number of `0`s and `1`s`.

Instead of checking every subarray (which would take **O(n²)** time), we keep track of:

- Number of `0`s seen so far.
- Number of `1`s seen so far.

At every index, compute:


diff = zeros - ones


### Important Observation

If the same `diff` appears again later, then the subarray between those two indices contains an equal number of `0`s and `1`s.

Why?

Suppose


Index 2:
zeros = 4
ones = 2
diff = 2


Later,


Index 7:
zeros = 8
ones = 6
diff = 2


Between index `3` and `7`:


Extra zeros = 8 - 4 = 4
Extra ones  = 6 - 2 = 4


So that subarray has equal numbers of `0`s and `1`s.

---

# Algorithm

1. Initialize


zeros = 0
ones = 0


2. Create a hashmap

unordered_map<int,int> f;


It stores


difference -> first index where it appeared


3. Traverse the array.

- If current element is `0`


zeros++;


- Otherwise

ones++;


4. Compute


diff = zeros - ones;


---

### Case 1

If


diff == 0


then from index `0` to current index, zeros and ones are equal.

Length is


i + 1


Update the answer.

---

### Case 2

If this `diff` has never appeared before

Store


f[diff] = i;


We only store the **first occurrence** because it gives the longest possible subarray later.

---

### Case 3

If this `diff` already exists

Then


len = i - f[diff];


Update the maximum length.

---

# Dry Run


nums = [0,1,0,0,1,1]


|Index|Value|Zeros|Ones|Diff|HashMap|Answer|
|------|-----|-----|----|----|-------|------|
|0|0|1|0|1|store (1→0)|0|
|1|1|1|1|0|equal from start|2|
|2|0|2|1|1|seen before at 0|2|
|3|0|3|1|2|store (2→3)|2|
|4|1|3|2|1|seen at 0 → length = 4|4|
|5|1|3|3|0|equal from start|6|

Final answer:


6


---

# Why Store Only the First Occurrence?

Suppose


diff = 2


appears at


index 3
index 8
index 10


If we overwrite the hashmap every time:


2 → 10


then at a later index we lose the chance to form the longest subarray.

Therefore, we only save the first occurrence.

---

# Complexity

### Time Complexity


O(n)


Each element is processed once.

### Space Complexity


O(n)


The hashmap may store one entry for each unique difference.

---

# Key Takeaways

- Convert the problem into tracking the difference between the counts of `0`s and `1`s.
- If the same difference appears twice, the subarray between those indices has equal numbers of `0`s and `1`s.
- Store only the first occurrence of each difference to maximize the subarray length.
- Using a hashmap reduces the solution from **O(n²)** to **O(n)**.
