# Interval List Intersections (LeetCode 986)

## Problem

You are given two lists of closed intervals:


firstList[i] = [starti, endi]
secondList[j] = [startj, endj]


Each list is:

- Sorted in ascending order by starting time.
- Contains non-overlapping intervals within the same list.

Return the intersection of these two interval lists.

Two intervals intersect if they share at least one common point.

---

## Example 1

**Input**


firstList = [[0,2],[5,10],[13,23],[24,25]]

secondList = [[1,5],[8,12],[15,24],[25,26]]


**Output**

[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]


---

## Example 2

**Input**


firstList = []

secondList = [[1,3]]


**Output**


[]


---

# Intuition

Since both interval lists are already sorted and contain no overlapping intervals within themselves, we never need to compare every interval with every other interval.

Instead, we use **two pointers**.

- Pointer `i` traverses `firstList`.
- Pointer `j` traverses `secondList`.

At every step, we compare the current intervals and determine whether they overlap.

If they overlap, we compute the intersection.

Then, we move forward the interval that finishes first because it cannot intersect with any future interval from the other list.

---

# Approach

## Step 1: Handle Empty Lists

If either list is empty,

return {};


because no intersections are possible.

---

## Step 2: Initialize Two Pointers

i = 0;
j = 0;


Both pointers start from the first interval of their respective lists.

---

## Step 3: Compare Current Intervals

Suppose


First Interval

[start1, end1]


and


Second Interval

[start2, end2]

There are two possibilities.

---

### Case 1

The first interval starts first.


start1 <= start2


The intervals overlap only if


end1 >= start2


Example


[1,7]

[5,9]


Since


7 >= 5

they intersect.

The intersection is


[max(start1,start2), min(end1,end2)]


which becomes


[5,7]


---

### Case 2

The second interval starts first.


start2 < start1


The intervals overlap only if


end2 >= start1


Example

[5,9]

[2,6]


Since


6 >= 5


they intersect.

The intersection is


[5,6]


---

## Step 4: Move the Correct Pointer

After processing the current pair, one of the intervals finishes first.

If


end2 <= end1


move pointer `j`.


j++;


Otherwise,


i++;


### Why?

Suppose


First

[2,10]


Second

[5,7]


The second interval ends first.

Once it ends, it cannot intersect with any future interval in the first list.

Therefore,


j++


Similarly,

if the first interval ends first,

i++


---

# Dry Run

### Input


firstList

[[0,2],[5,10],[13,23],[24,25]]

secondList

[[1,5],[8,12],[15,24],[25,26]]


---

### Compare


[0,2]

[1,5]


Overlap


[1,2]


First interval ends first.

Move `i`.

---

### Compare

[5,10]

[1,5]


Overlap

[5,5]

Second interval ends first.

Move `j`.

---

### Compare


[5,10]

[8,12]


Overlap

[8,10]


First interval ends first.

Move `i`.

---

### Compare


[13,23]

[15,24]


Overlap


[15,23]


First interval ends first.

Move `i`.

---

### Compare


[24,25]

[15,24]


Overlap

[24,24]


Second interval ends first.

Move `j`.

---

### Compare


[24,25]

[25,26]


Overlap


[25,25]


First interval ends first.

Move `i`.

Loop ends.

Final answer


[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]


---

# Why Move the Interval That Ends First?

Suppose


First

[3,12]


Second

[6,8]


After finding their intersection,


[6,8]


the second interval has already finished.

It cannot overlap with any future interval from the first list.

Therefore, we safely move pointer `j`.

This guarantees that every interval is processed exactly once.

---

# Complexity Analysis

Let

- `n = firstList.size()`
- `m = secondList.size()`

### Time Complexity

Each pointer moves only forward.


O(n + m)


---

### Space Complexity

Ignoring the output array,


O(1)


The output array stores only the intersections.

---


# Key Takeaways

- Both interval lists are already sorted, making the **two-pointer technique** ideal.
- Two intervals overlap if the end of the earlier-starting interval is greater than or equal to the start of the later-starting interval.
- The intersection is always:
  - Start = `max(start1, start2)`
  - End = `min(end1, end2)`
- After processing a pair of intervals, advance the pointer of the interval that ends first because it cannot contribute to future intersections.
- Each interval is visited at most once, giving an efficient **O(n + m)** solution.
