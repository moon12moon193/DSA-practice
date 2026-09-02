# ✈️ Cheapest Flights Within K Stops

## 📌 Problem

You are given `n` cities and a list of flights.

Each flight is represented as:

```cpp
[source, destination, price]
```

You are also given:

* `src` → starting city
* `dst` → destination city
* `k` → maximum number of stops allowed

The goal is to find the **cheapest price** from `src` to `dst` using **at most `k` stops**.

If it is impossible to reach the destination within `k` stops, return:

```text
-1
```

---

## 💡 Approach

This solution uses a modified version of the **Bellman-Ford algorithm**.

Normally, Bellman-Ford relaxes all edges `V - 1` times to find the shortest path.

Here, we have an additional restriction:

> We can use at most `k + 1` flights because `k` stops means `k + 1` edges.

Therefore, we relax all flights exactly:

```text
k + 1 times
```

---

## 🧠 Why Do We Use Two Arrays?

We use:

```cpp
vector<int> res(n, INT_MAX);
vector<int> temp(n, INT_MAX);
```

### `res`

Stores the cheapest prices obtained from the **previous iteration**.

### `temp`

Stores the updated prices for the **current iteration**.

This separation is important.

If we directly updated `res` while iterating through the flights, one iteration could use multiple newly updated edges and accidentally create a path with more than one additional flight.

Using two arrays ensures that:

```text
Current iteration
       ↓
Read from res
       ↓
Write to temp
       ↓
res = temp
```

Each iteration represents adding **at most one more flight**.

---

## 🔍 Initialization

Initially, the cost of reaching the source is `0`:

```cpp
res[src] = 0;
temp[src] = 0;
```

Every other city is unreachable:

```text
INF
```

For example, if:

```text
src = 0
n = 4
```

then:

```text
res = [0, INF, INF, INF]
```

---

## 🔄 Relaxation Process

For every iteration, we process every flight:

```cpp
for (int j = 0; j < flights.size(); j++) {

    int source = flights[j][0];
    int dest = flights[j][1];
    int weight = flights[j][2];

    if (res[source] != INT_MAX &&
        temp[dest] > res[source] + weight) {

        temp[dest] = res[source] + weight;
    }
}
```

The relaxation condition is:

```cpp
temp[dest] > res[source] + weight
```

This asks:

> Is reaching `dest` through `source` cheaper than the price we currently have?

If yes, update the price.

---

## 🔁 Updating `res`

After processing all flights:

```cpp
res = temp;
```

Now the current results become the previous results for the next iteration.

So the process looks like:

```text
Iteration 0
    ↓
Paths using at most 1 flight

Iteration 1
    ↓
Paths using at most 2 flights

Iteration 2
    ↓
Paths using at most 3 flights

...
```

Since `k` stops allow at most `k + 1` flights, we run:

```cpp
for (int i = 0; i <= k; i++)
```

which gives exactly `k + 1` iterations.

---

## 📝 Example

Consider:

```text
n = 4

flights = [
    [0, 1, 100],
    [1, 2, 100],
    [2, 3, 100]
]

src = 0
dst = 3
k = 2
```

We can use at most:

```text
k + 1 = 3 flights
```

The available route is:

```text
0 → 1 → 2 → 3
```

Cost:

```text
100 + 100 + 100 = 300
```

Therefore:

```text
Answer = 300
```

### Iteration 0

Start:

```text
res = [0, INF, INF, INF]
```

After processing flights:

```text
temp = [0, 100, INF, INF]
```

Then:

```text
res = temp
```

So:

```text
res = [0, 100, INF, INF]
```

We can now reach city `1` using 1 flight.

---

### Iteration 1

Starting:

```text
res = [0, 100, INF, INF]
```

After relaxation:

```text
res = [0, 100, 200, INF]
```

We can now reach city `2` using 2 flights.

---

### Iteration 2

Starting:

```text
res = [0, 100, 200, INF]
```

After relaxation:

```text
res = [0, 100, 200, 300]
```

We can now reach city `3`.

Therefore:

```text
answer = 300
```

---

## 💻 Code

```cpp
class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> res(n, INT_MAX);
        vector<int> temp(n, INT_MAX);

        res[src] = 0;
        temp[src] = 0;

        // k stops = k + 1 flights
        for (int i = 0; i <= k; i++) {

            for (int j = 0; j < flights.size(); j++) {

                int source = flights[j][0];
                int dest = flights[j][1];
                int weight = flights[j][2];

                if (res[source] != INT_MAX &&
                    temp[dest] > res[source] + weight) {

                    temp[dest] = res[source] + weight;
                }
            }

            // Move current results to previous results
            res = temp;
        }

        if (res[dst] == INT_MAX) {
            return -1;
        }

        return res[dst];
    }
};
```

---

## ⚠️ Important Detail

A common mistake is to update `res` directly:

```cpp
res[dest] = res[source] + weight;
```

while iterating through the flights.

That can cause the same iteration to use an already-updated value and effectively use multiple flights in a single iteration.

Instead:

```cpp
res → read previous results
temp → store current results
```

This prevents that problem.

---

## ⏱️ Complexity

Let:

* `V` = number of cities
* `E` = number of flights

We process all `E` flights `k + 1` times.

### Time Complexity

```text
O((k + 1) × E)
```

or simply:

```text
O(k × E)
```

### Space Complexity

We use two arrays of size `n`:

```text
O(V)
```

Therefore:

```text
Space Complexity = O(V)
```

---

## 🔑 Key Concepts

This problem is useful for understanding:

* Bellman-Ford Algorithm
* Edge Relaxation
* Shortest Path
* Limited Number of Edges
* Dynamic Programming
* Graphs
* Two-Array Optimization
* `INT_MAX` for unreachable nodes

---

## 🎯 Key Pattern to Remember

The main idea is:

```text
k stops
   ↓
k + 1 flights
   ↓
Run relaxation k + 1 times
   ↓
res = previous iteration
temp = current iteration
```

The most important line is:

```cpp
res = temp;
```

because it allows each iteration to build upon the results of the previous number of flights while keeping the number of flights within the required limit.
