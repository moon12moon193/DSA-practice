# Merge Intervals (LeetCode 56)

## Problem

Given an array of intervals where:


intervals[i] = [starti, endi]


merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

---

## Example 1

**Input**


intervals = [[1,3],[2,6],[8,10],[15,18]]


**Output**


[[1,6],[8,10],[15,18]]


### Explanation

- `[1,3]` and `[2,6]` overlap.
- They are merged into `[1,6]`.

---

## Example 2

**Input**


intervals = [[1,4],[4,5]]


**Output**


[[1,5]]


### Explanation

Intervals touching at an endpoint are considered overlapping.

---

# Intuition

Merging intervals becomes much easier if the intervals are arranged according to their starting points.

For example,


[[8,10],[1,3],[2,6],[15,18]]


is difficult to process directly.

After sorting,


[[1,3],[2,6],[8,10],[15,18]]


all possible overlapping intervals become adjacent.

Then we simply compare each interval with the previous merged interval.

---

# Approach

## Step 1: Sort the intervals


sort(intervals.begin(), intervals.end());


After sorting,


[[5,8],[1,3],[2,6]]


becomes


[[1,3],[2,6],[5,8]]


---

## Step 2: Initialize the first interval


start1 = intervals[0][0];
end1 = intervals[0][1];


This represents the current interval that we are trying to merge.

---

## Step 3: Traverse the remaining intervals

For every interval,


start2 = intervals[i][0];


there are two cases.

---

### Case 1: Overlapping

If

start2 <= end1


then the intervals overlap.

Example


Current : [1,4]

Next    : [3,7]


Since


3 <= 4

they overlap.

Update


end1 = max(end1, end2);


Result


[1,7]


---

### Case 2: Non-overlapping

If


start2 > end1


Example


Current : [1,6]

Next    : [8,10]


They do not overlap.

Store the current merged interval.


res.push_back({start1,end1});


Now start a new interval.


start1 = start2;
end1 = end2;


---

## Step 4: Add the last interval

After the loop finishes, the final merged interval has not yet been added.

So,


res.push_back({start1,end1});

---

# Dry Run

Input


[[1,3],[2,6],[8,10],[15,18]]


### Initially


Current = [1,3]


---

### Compare with [2,6]


2 <= 3


Merge


Current = [1,6]


---

### Compare with [8,10]


8 > 6


No overlap.

Store


[1,6]


Current becomes


[8,10]


---

### Compare with [15,18]


15 > 10


No overlap.

Store


[8,10]


Current becomes


[15,18]


---

Loop ends.

Store the final interval.


[15,18]


Final answer


[[1,6],[8,10],[15,18]]


---

# Why Sorting is Necessary

Consider


[[5,8],[1,3],[2,6]]


Without sorting,


Current = [5,8]

Next = [1,3]


Although they overlap after considering `[2,6]`, they are processed in the wrong order.

Sorting guarantees that every interval that can overlap appears immediately after the previous one.

---

# Complexity Analysis

### Time Complexity

Sorting


O(n log n)


Traversing all intervals


O(n)


Overall


O(n log n)


---

### Space Complexity

Ignoring the output array,


O(1)


Including the output array,


O(n)


---



# Key Takeaways

- Sort the intervals by their starting points before merging.
- Keep track of the current merged interval using `start1` and `end1`.
- If the next interval starts before or at the current interval's end, merge them by updating the end.
- If there is no overlap, store the current interval and start a new one.
- Don't forget to add the last merged interval after the loop.
