# Insert Interval (LeetCode 57)

## Problem

You are given a list of **non-overlapping intervals** sorted in ascending order by their starting points.

You are also given a new interval.

Insert the new interval into the list such that the resulting list is still sorted and contains no overlapping intervals.

---

## Example 1

**Input**


intervals = [[1,3],[6,9]]
newInterval = [2,5]


**Output**


[[1,5],[6,9]]


---

## Example 2

**Input**


intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]


**Output**


[[1,2],[3,10],[12,16]]


---

# Intuition

Instead of trying to merge the new interval while traversing the original intervals, this solution divides the problem into **two simple steps**:

1. Insert the new interval into the correct sorted position.
2. Run the **Merge Intervals** algorithm on the resulting list.

This makes the solution easy to understand because the insertion and merging logic are handled separately.

---

# Approach

## Step 1: Insert the New Interval

Create a new array `ans1`.

Traverse all existing intervals.

If the new interval has not been inserted yet and its starting point is smaller than the current interval's starting point,




insert the new interval first.

Example

Original


[[1,3],[6,9]]


New interval

[2,5]


Result after insertion


[[1,3],[2,5],[6,9]]


If the new interval has the largest starting point, append it after the loop.

---

## Step 2: Merge All Intervals

Now `ans1` may contain overlapping intervals.

Use the standard Merge Intervals algorithm.

Initialize


start1 = ans1[0][0];
end1 = ans1[0][1];


For every remaining interval,


start2 = ans1[i][0];
end2 = ans1[i][1];


there are two cases.

### Case 1: Overlapping

If




merge them by extending the ending point.


end1 = max(end1, end2);


Example


Current : [1,3]

Next    : [2,5]


Result


[1,5]


---

### Case 2: Non-overlapping

If


start2 > end1


store the current merged interval.


ans2.push_back({start1,end1});


Start a new current interval.


start1 = start2;
end1 = end2;


---

After the loop ends, push the last merged interval.

---

# Dry Run

### Input


intervals = [[1,3],[6,9]]

newInterval = [2,5]


---

### Step 1: Insert

ans1

[1,3]
[2,5]
[6,9]


---

### Step 2: Merge

Current


[1,3]


Compare


[2,5]


Since

2 <= 3


Merge


[1,5]


Compare


[6,9]


Since

6 > 5


Store


[1,5]


Current becomes


[6,9]


Push the last interval.

Final answer


[[1,5],[6,9]]


---

# Helper Function

The helper function


mergeInterval(ans1, ans2)


takes the intervals after insertion and merges every overlapping interval.

It is exactly the same logic as the Merge Intervals problem.

---

# Complexity Analysis

Let `n` be the number of intervals.

### Inserting the new interval


O(n)


### Merging


O(n)


### Total Time Complexity


O(n)


### Space Complexity

A new array is created to store the intervals.

O(n)


---

# Key Takeaways

- Since the original intervals are already sorted, insert the new interval at its correct position.
- After insertion, overlapping intervals may exist.
- Reuse the Merge Intervals algorithm to combine all overlapping intervals.
- Separating insertion and merging makes the code easier to understand and maintain.
