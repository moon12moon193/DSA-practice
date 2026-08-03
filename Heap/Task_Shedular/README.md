# Task Scheduler (LeetCode 621)

## Problem

You are given a list of CPU tasks represented by uppercase English letters and a non-negative integer `n`.

The same type of task must have a **cooldown period** of `n` intervals before it can be executed again.

During each interval, the CPU can either:

- Execute one task, or
- Remain idle.

Return the **minimum number of intervals** required to complete all tasks.

---

## Example 1

**Input**

```cpp
tasks = ['A','A','A','B','B','B']

n = 2
```

**Output**

```cpp
8
```

### One Possible Schedule

```text
A → B → Idle → A → B → Idle → A → B
```

Total intervals:

```text
8
```

---

## Example 2

**Input**

```cpp
tasks = ['A','C','A','B','D','B']

n = 1
```

**Output**

```cpp
6
```

### One Possible Schedule

```text
A → B → A → B → C → D
```

No idle intervals are needed.

---

# Intuition

Tasks with the **highest remaining frequency** should be executed first because they are the hardest to place without violating the cooldown constraint.

A **Max Heap** always provides the task with the highest remaining frequency.

Additionally, every task remembers the **next interval when it becomes available** after being executed.

At every interval:

- Choose the highest-frequency task whose cooldown has finished.
- If no task is available, the CPU stays idle.
- Continue until every task has been completed.

---

# Approach

## Step 1: Count Frequencies

Use a HashMap to count how many times each task appears.

```cpp
unordered_map<char,int> f;
```

Example:

```text
Tasks

A A A B B B
```

Frequency Map

```text
A → 3
B → 3
```

---

## Step 2: Track Availability

Maintain another HashMap that stores the earliest interval when each task can be executed again.

Initially every task is available.

```cpp
free[task] = 1;
```

---

## Step 3: Create a Max Heap

Store

```text
(frequency, task)
```

The heap always keeps the task with the highest remaining frequency at the top.

---

## Step 4: Simulate CPU Execution

Maintain a variable

```text
seat
```

representing the current CPU interval.

For every interval:

- Remove tasks from the heap until an available task is found.
- If the task's cooldown has expired:

  - Execute it.
  - Decrease its frequency.
  - Update its next available interval.

```text
next available = current interval + n + 1
```

- If it still has remaining occurrences, push it back into the heap.
- Any skipped tasks are temporarily stored and pushed back after the interval.

If no task is available,

the interval simply becomes an idle interval.

Increase the interval counter and continue.

---

## Step 5: Return Total Intervals

When the heap becomes empty,

all tasks have been completed.

Return

```text
seat - 1
```

because the interval counter is incremented after the final execution.

---

# Dry Run

### Input

```text
tasks =

A A A B B B

n = 2
```

---

### Frequency Map

```text
A → 3
B → 3
```

---

### Interval 1

Available:

```text
A
B
```

Choose

```text
A
```

Result

```text
A
```

A becomes available again at

```text
4
```

---

### Interval 2

Choose

```text
B
```

Result

```text
A B
```

B becomes available again at

```text
5
```

---

### Interval 3

Neither

```text
A
```

nor

```text
B
```

is available.

CPU remains

```text
Idle
```

---

### Interval 4

Choose

```text
A
```

---

### Interval 5

Choose

```text
B
```

---

### Interval 6

Idle

---

### Interval 7

Choose

```text
A
```

---

### Interval 8

Choose

```text
B
```

Finished.

Total intervals:

```text
8
```

---

# Why Use a Max Heap?

The task with the highest remaining frequency is the most difficult to schedule.

Choosing it first:

- Reduces the chance of future idle intervals.
- Ensures frequently occurring tasks are distributed as early as possible.
- Produces an efficient greedy scheduling strategy.

The availability map guarantees that cooldown rules are never violated.

---

# Complexity Analysis

Let

```text
m = number of distinct task types
```

and

```text
T = total intervals executed
```

### Time Complexity

Counting frequencies:

```text
O(n)
```

Each heap operation:

```text
O(log m)
```

Overall:

```text
O(T log m)
```

where `T` includes both task executions and idle intervals.

---

### Space Complexity

Frequency map:

```text
O(m)
```

Availability map:

```text
O(m)
```

Heap:

```text
O(m)
```

Overall:

```text
O(m)
```

---

# C++ Solution

```cpp
class Solution {
public:

    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {

            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> f;
        unordered_map<char, int> free;

        int seat = 1;

        for (char task : tasks) {
            f[task]++;
            free[task] = 1;
        }

        priority_queue<
            pair<int, char>,
            vector<pair<int, char>>,
            cmp
        > pq;

        for (auto elem : f) {
            pq.push({elem.second, elem.first});
        }

        while (!pq.empty()) {

            vector<pair<int, char>> skipped;

            while (!pq.empty()) {

                auto current = pq.top();
                pq.pop();

                int freq = current.first;
                char task = current.second;

                if (free[task] <= seat) {

                    free[task] = seat + n + 1;
                    freq--;

                    if (freq > 0) {
                        pq.push({freq, task});
                    }

                    break;

                } else {

                    skipped.push_back({freq, task});
                }
            }

            seat++;

            for (auto &item : skipped) {
                pq.push(item);
            }
        }

        return seat - 1;
    }
};
```

---

# Key Takeaways

- Use a **HashMap** to count the frequency of each task.
- Maintain another **HashMap** to record when each task becomes available after its cooldown.
- Use a **Max Heap** to always select the task with the highest remaining frequency.
- Temporarily skip tasks that are still in cooldown and reinsert them into the heap after each interval.
- This approach combines **Greedy + Heap + HashMap + Simulation** to efficiently schedule tasks while respecting cooldown constraints.
