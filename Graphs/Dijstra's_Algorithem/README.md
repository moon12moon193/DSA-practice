# Dijkstra's Shortest Path Algorithm

## Overview

This implementation finds the shortest distance from a given source vertex to every other vertex in a **weighted undirected graph**.

The graph is represented using an adjacency list, and a **min-heap priority queue** is used to always process the vertex with the smallest currently known distance.

---

## Approach

### 1. Create an Adjacency List

The graph is converted into an adjacency list where each vertex stores:

```text
(neighbour, weight)
```

Since the graph is undirected, every edge is added in both directions.

```cpp
adj[source].push_back({dest, weight});
adj[dest].push_back({source, weight});
```

---

### 2. Initialize Distances

A distance array is created:

```cpp
vector<int> res(V, INT_MAX);
```

Initially, every vertex has an infinite distance.

The source vertex is set to distance `0`:

```cpp
res[src] = 0;
```

---

### 3. Use a Min-Heap

A priority queue is used to store:

```text
(distance, vertex)
```

The `greater<pair<int,int>>` makes it a **min-priority queue**, so the vertex with the smallest distance is processed first.

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

The source is inserted:

```cpp
pq.push({0, src});
```

---

### 4. Process the Graph

While the priority queue is not empty:

1. Remove the vertex with the smallest distance.
2. Check all of its neighbouring vertices.
3. Calculate the new possible distance.
4. If the new distance is smaller, update the distance array.
5. Push the updated distance into the priority queue.

```cpp
if(disc + wt < res[neighbour]) {
    res[neighbour] = disc + wt;
    pq.push({disc + wt, neighbour});
}
```

This process is called **relaxation**.

---

### 5. Ignore Outdated Entries

The priority queue can contain multiple entries for the same vertex.

For example:

```text
(10, 3)
(5, 3)
```

When `(10, 3)` is removed, the current shortest distance may already be `5`.

Therefore:

```cpp
if(disc > res[node]) {
    continue;
}
```

This prevents processing an outdated entry.

---

## Example

Consider the graph:

```text
       2
   0 ----- 1
   |       |
  4|       |3
   |       |
   2 ----- 3
       1
```

If the source is:

```text
src = 0
```

The algorithm calculates the shortest distances from vertex `0` to every vertex.

The result will contain the minimum distance for each vertex.

---

## Data Structures Used

### Adjacency List

```cpp
vector<vector<pair<int,int>>> adj(V);
```

Stores the graph efficiently.

### Distance Array

```cpp
vector<int> res(V, INT_MAX);
```

Stores the shortest known distance from the source.

### Priority Queue

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

Acts as a min-heap and gives the vertex with the smallest distance first.

---

## Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

### Time Complexity

```text
O((V + E) log V)
```

For a graph where `E` is much larger than `V`, this is commonly written as:

```text
O(E log V)
```

### Space Complexity

```text
O(V + E)
```

The adjacency list requires `O(V + E)` space, while the distance array and priority queue require additional space.

---

## Important Condition

Dijkstra's algorithm works correctly when **all edge weights are non-negative**.

It should not be used when the graph contains negative-weight edges.

For graphs containing negative weights, algorithms such as **Bellman-Ford** may be more appropriate.

---

## Key Concepts

* Weighted graph
* Undirected graph
* Adjacency list
* Priority queue / min-heap
* Shortest path
* Relaxation
* Distance array
* Greedy approach
* Non-negative edge weights

---

## Implementation

```cpp
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        vector<int> res(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Build adjacency list
        for(int i = 0; i < edges.size(); i++) {
            int source = edges[i][0];
            int dest = edges[i][1];
            int weight = edges[i][2];

            adj[source].push_back({dest, weight});
            adj[dest].push_back({source, weight});
        }

        // Source distance
        res[src] = 0;
        pq.push({0, src});

        // Dijkstra's algorithm
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            int disc = p.first;
            int node = p.second;

            // Ignore outdated entry
            if(disc > res[node]) {
                continue;
            }

            // Relax neighbouring vertices
            for(int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i].first;
                int wt = adj[node][i].second;

                if(disc + wt < res[neighbour]) {
                    res[neighbour] = disc + wt;
                    pq.push({disc + wt, neighbour});
                }
            }
        }

        return res;
    }
};
```

## Summary

The algorithm maintains the shortest known distance to every vertex and repeatedly chooses the vertex with the smallest distance using a min-heap. It then relaxes all of that vertex's edges.

The main idea is:

```text
Pick minimum distance vertex
        ↓
Visit its neighbours
        ↓
Calculate new distance
        ↓
If new distance is smaller
        ↓
Update + push into priority queue
        ↓
Repeat
```

This approach efficiently computes the shortest distance from one source vertex to all other vertices in a graph with non-negative edge weights.
