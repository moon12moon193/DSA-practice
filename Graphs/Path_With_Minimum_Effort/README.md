# Minimum Effort Path

## Overview

This implementation finds a path from the **top-left cell** of a grid to the **bottom-right cell** such that the **maximum absolute height difference between two consecutive cells is minimized**.

Unlike a normal shortest-path problem where we minimize the total sum of edge weights, here the cost of a path is determined by its **largest height difference**.

---

## Problem Concept

For two adjacent cells:

```text
height difference = |height[current] - height[next]|
```

The effort of an entire path is:

```text
maximum height difference encountered along the path
```

The goal is to find the path whose maximum difference is as small as possible.

### Example

Suppose a path has height differences:

```text
2 → 4 → 1 → 3
```

The effort of this path is:

```text
max(2, 4, 1, 3) = 4
```

We do **not** add them together.

So:

```text
Total = 2 + 4 + 1 + 3 = 10
Effort = max(2, 4, 1, 3) = 4
```

The algorithm minimizes the second value.

---

## Approach

This problem can be solved using a modified version of **Dijkstra's algorithm**.

Instead of storing the shortest total distance to each cell, we store the **minimum possible effort** required to reach each cell.

---

## 1. Distance / Effort Matrix

We create:

```cpp
vector<vector<int>> res(n);
```

Each cell initially has effort:

```text
INT_MAX
```

This means that initially we do not know how much effort is required to reach any cell.

The starting cell has effort `0`:

```cpp
res[0][0] = 0;
```

---

## 2. Priority Queue

The priority queue stores:

```text
(effort, (row, column))
```

It is implemented as a min-heap:

```cpp
priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
```

The structure looks like:

```text
pair
 ├── effort
 └── pair
      ├── row
      └── column
```

For example:

```cpp
pq.push({5, {2, 3}});
```

means:

```text
effort = 5
row    = 2
column = 3
```

The minimum-effort cell is always processed first.

---

## 3. Four Possible Directions

From every cell, we can move:

```text
       Up
       ↑
Left ← Cell → Right
       ↓
      Down
```

The direction arrays are:

```cpp
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
```

These represent:

```text
(-1,  0) → Up
( 1,  0) → Down
( 0, -1) → Left
( 0,  1) → Right
```

---

## 4. Boundary Checking

The `isValid()` function checks whether a cell exists inside the grid.

```cpp
bool isValid(int row, int col, int n, int m) {
    if(row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }

    return true;
}
```

This prevents accessing invalid positions such as:

```text
row = -1
col = m
```

---

## 5. Calculate Height Difference

For the current cell and its neighbour:

```cpp
int absDiff = abs(
    heights[row][col] - heights[r][c]
);
```

This gives the effort required to move from the current cell to the neighbouring cell.

For example:

```text
Current height = 10
Neighbour height = 6

Difference = |10 - 6|
           = 4
```

---

## 6. Calculate New Effort

This is the most important part of the algorithm:

```cpp
int newWeight = max(absDiff, disc);
```

Why do we use `max()`?

Because the effort of a path is the **maximum height difference encountered so far**.

Suppose the current path has:

```text
Previous effort = 5
New edge difference = 3
```

Then:

```text
max(5, 3) = 5
```

The effort remains `5`.

But if:

```text
Previous effort = 5
New edge difference = 8
```

then:

```text
max(5, 8) = 8
```

The new effort becomes `8`.

---

## 7. Relaxation

If the newly calculated effort is smaller than the previously known effort:

```cpp
if(newWeight < res[r][c]) {
    res[r][c] = newWeight;
    pq.push({newWeight, {r, c}});
}
```

we update the neighbour.

This is similar to relaxation in normal Dijkstra's algorithm.

The difference is that normal Dijkstra uses:

```cpp
newDistance = currentDistance + edgeWeight;
```

while this problem uses:

```cpp
newEffort = max(currentEffort, edgeDifference);
```

### Comparison

```text
Normal Dijkstra:

newDistance = distance + weight


Minimum Effort Path:

newEffort = max(effort, heightDifference)
```

---

## 8. Ignore Outdated Entries

The priority queue may contain multiple entries for the same cell.

Therefore:

```cpp
if(disc > res[row][col]) {
    continue;
}
```

If the effort taken from the priority queue is greater than the currently known minimum effort, that entry is outdated and can be ignored.

This improves efficiency.

---

## Algorithm Flow

```text
Start at (0,0)
      ↓
Effort = 0
      ↓
Push (0, (0,0)) into min-heap
      ↓
Take minimum-effort cell
      ↓
Check its 4 neighbours
      ↓
Calculate height difference
      ↓
newEffort = max(currentEffort, heightDifference)
      ↓
Is newEffort smaller?
      ↓
   Yes ───────→ Update + Push
      ↓
Repeat
      ↓
Reach bottom-right cell
      ↓
Return its minimum effort
```

---

## Example

Consider:

```text
1  2  2
3  8  2
5  3  5
```

One possible path is:

```text
1 → 2 → 2 → 2 → 5
```

The height differences are:

```text
|1-2| = 1
|2-2| = 0
|2-2| = 0
|2-5| = 3
```

Therefore:

```text
Effort = max(1, 0, 0, 3)
       = 3
```

The algorithm examines different possible paths and finds the path with the smallest possible maximum difference.

---

## Why Dijkstra Works Here

Each cell can be considered a graph vertex.

Moving between adjacent cells creates an edge whose weight is:

```text
|height[current] - height[next]|
```

However, instead of adding edge weights, the path cost is defined as the maximum edge weight.

The modified Dijkstra approach works by maintaining:

```text
minimum effort required to reach each cell
```

and always processing the cell with the smallest known effort.

---

## Data Structures Used

### Grid

```cpp
vector<vector<int>>& heights
```

Stores the height of every cell.

### Effort Matrix

```cpp
vector<vector<int>> res
```

Stores the minimum effort required to reach every cell.

### Priority Queue

```cpp
priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
```

Stores cells according to their current minimum effort.

---

## Complexity

Let:

```text
n = number of rows
m = number of columns
```

There are:

```text
n × m
```

cells.

Each cell can have at most four neighbours.

### Time Complexity

```text
O(n × m × log(n × m))
```

The priority queue operations take logarithmic time.

### Space Complexity

```text
O(n × m)
```

The effort matrix and priority queue require space proportional to the number of cells.

---

## Important Difference from Normal Dijkstra

This problem is a useful example of how Dijkstra's algorithm can be modified depending on how the **path cost** is defined.

### Standard shortest path

```cpp
newDistance = currentDistance + edgeWeight;
```

### Minimum effort path

```cpp
newEffort = max(currentEffort, edgeDifference);
```

This is the key idea to remember.

---

## Implementation

```cpp
class Solution { 
public: 

    bool isValid(int row, int col, int n, int m) { 
        if(row < 0 || row >= n || col < 0 || col >= m) { 
            return false; 
        } 

        return true; 
    } 

    int minimumEffortPath(vector<vector<int>>& heights) { 

        int n = heights.size(); 
        int m = heights[0].size(); 

        vector<vector<int>> res(n); 

        for(int i = 0; i < n; i++) { 
            vector<int> t(m, INT_MAX); 
            res[i] = t; 
        } 

        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq; 

        int x[4] = {-1, 1, 0, 0}; 
        int y[4] = {0, 0, -1, 1}; 

        res[0][0] = 0; 
        pq.push({0, {0, 0}}); 

        while(!pq.empty()) { 

            pair<int, pair<int,int>> p = pq.top(); 
            pq.pop(); 

            int disc = p.first; 
            int row = p.second.first; 
            int col = p.second.second; 

            if(disc > res[row][col]) { 
                continue; 
            } 

            for(int i = 0; i < 4; i++) { 

                int r = row + x[i]; 
                int c = col + y[i]; 

                if(!isValid(r, c, n, m)) { 
                    continue; 
                } 

                int absDiff = abs(
                    heights[row][col] - heights[r][c]
                ); 

                int newWeight = max(absDiff, disc); 

                if(newWeight < res[r][c]) { 
                    res[r][c] = newWeight; 
                    pq.push({newWeight, {r, c}}); 
                } 
            } 
        } 

        return res[n-1][m-1]; 
    } 
};
```

## Key Takeaway

The most important line is:

```cpp
int newWeight = max(absDiff, disc);
```

Instead of minimizing the **sum of weights**, we minimize the **maximum edge difference along the path**.

```text
Path cost = maximum edge difference
```

That single change turns the normal Dijkstra relaxation formula into the solution for the minimum-effort path problem.
