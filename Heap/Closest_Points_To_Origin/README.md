# K Closest Points to Origin (LeetCode 973)

## Problem

Given an array of points where each point is represented as:

```text
[x, y]
```

Return the **k closest points to the origin (0,0)**.

The distance between a point `(x, y)` and the origin is:

```text
√(x² + y²)
```

Since the square root is monotonic, comparing **x² + y²** is sufficient.

The answer may be returned in **any order**.

---

## Example 1

**Input**

```cpp
points = [[1,3],[-2,2]]

k = 1
```

**Output**

```cpp
[[-2,2]]
```

---

## Example 2

**Input**

```cpp
points = [[3,3],[5,-1],[-2,4]]

k = 2
```

**Output**

```cpp
[[3,3],[-2,4]]
```

---

# Intuition

To find the `k` closest points, we first calculate the squared distance of every point from the origin.

Instead of sorting all points, we maintain a **Max Heap** of size `k`.

The heap stores:

```text
(distance, index)
```

- The point with the **largest distance** among the current `k` closest points stays at the top.
- Whenever a closer point is found, it replaces the farthest point in the heap.

This avoids sorting the entire array and makes the solution efficient.

---

# Approach

## Step 1: Calculate Squared Distance

For every point,

```text
distance = x² + y²
```

There is no need to calculate the square root because:

```text
√a < √b  ⇔  a < b
```

Store each point's index and its squared distance.

Example:

```text
Point (1,3)

Distance = 1² + 3² = 10
```

---

## Step 2: Create a Max Heap

Use a custom comparator so that the point with the **largest distance** remains on top.

Each heap element stores:

```text
(distance, index)
```

---

## Step 3: Process Every Point

### Case 1

If the heap contains fewer than `k` points,

simply insert the current point.

```cpp
pq.push({distance, index});
```

---

### Case 2

If the heap already contains `k` points,

compare the current distance with the largest distance in the heap.

If

```cpp
distance < pq.top().first
```

then

- Remove the farthest point.
- Insert the current closer point.

Otherwise,

ignore it.

The heap size always remains `k`.

---

## Step 4: Build the Result

The heap now contains the indices of the `k` closest points.

Retrieve the coordinates using those indices and store them in the answer.

Return the result.

---

# Dry Run

### Input

```text
points =

[
 [1,3],
 [-2,2]
]

k = 1
```

---

### Calculate Distances

```text
(1,3)

Distance = 1² + 3² = 10
```

```text
(-2,2)

Distance = (-2)² + 2² = 8
```

---

### Insert First Point

Heap

```text
[(10,0)]
```

Top

```text
10
```

---

### Process Second Point

Current distance

```text
8
```

Top distance

```text
10
```

Since

```text
8 < 10
```

Remove

```text
10
```

Insert

```text
8
```

Heap

```text
[(8,1)]
```

---

### Build Answer

Index stored

```text
1
```

Point

```text
[-2,2]
```

Return

```text
[[-2,2]]
```

---

# Why Use a Max Heap?

Suppose

```text
k = 3
```

Current heap stores

```text
Distance

5
8
12
```

Top

```text
12
```

Now a new point has distance

```text
7
```

Since

```text
7 < 12
```

remove

```text
12
```

and insert

```text
7
```

Heap becomes

```text
5
7
8
```

The heap always stores the **k closest points**, while the farthest among them stays at the top for easy replacement.

---

# Complexity Analysis

### Time Complexity

Calculating distances:

```text
O(n)
```

Each heap operation takes:

```text
O(log k)
```

Processing all points:

```text
O(n log k)
```

---

### Space Complexity

HashMap:

```text
O(n)
```

Max Heap:

```text
O(k)
```

Overall:

```text
O(n + k)
```

---

# C++ Solution

```cpp
class Solution {
public:

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {

            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> result;

        unordered_map<int, int> f;

        // Store squared distances
        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            f[i] = dist;
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            cmp
        > pq;

        for (auto elem : f) {

            int dist = elem.second;
            int index = elem.first;

            if (pq.size() < k) {

                pq.push({dist, index});

            } else {

                if (dist < pq.top().first) {

                    pq.pop();
                    pq.push({dist, index});
                }
            }
        }

        while (!pq.empty()) {

            int index = pq.top().second;

            result.push_back({
                points[index][0],
                points[index][1]
            });

            pq.pop();
        }

        return result;
    }
};
```

---

# Key Takeaways

- The Euclidean distance can be compared using **x² + y²**, avoiding the expensive square root calculation.
- Use a **Max Heap** of size `k` to maintain the `k` closest points.
- Store **(distance, index)** pairs so the original coordinates can be retrieved later.
- Whenever a closer point is found, replace the farthest point currently in the heap.
- This approach runs in **O(n log k)** time and is a common interview pattern for **Top K** and **Heap** problems.
