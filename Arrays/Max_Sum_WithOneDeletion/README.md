# LeetCode 1186 - Maximum Subarray Sum with One Deletion

## Problem

Given an integer array `arr`, return the **maximum sum of a non-empty subarray** after **deleting at most one element**.

- You may choose **not** to delete any element.
- The subarray must remain **non-empty** after the deletion.

---

## Idea

This problem is an extension of **Kadane's Algorithm**.

At every index, we maintain two states:

### 1. `noDelete`

Represents:

> Maximum subarray sum ending at the current index **without using any deletion**.

This is exactly the same state used in Kadane's Algorithm.

Transition:

```cpp
noDelete = max(arr[i], previousNoDelete + arr[i]);
```

There are only two choices:

- Start a new subarray from the current element.
- Extend the previous subarray.

---

### 2. `oneDelete`

Represents:

> Maximum subarray sum ending at the current index **after exactly one deletion has been used**.

There are two possibilities.

#### Case 1: Deletion was already used earlier

Simply extend the previous subarray.

```cpp
previousOneDelete + arr[i]
```

#### Case 2: Delete the current element

If the deletion has not been used yet, delete the current element.

The subarray then ends at the previous index.

Therefore,

```cpp
previousNoDelete
```

Transition:

```cpp
oneDelete = max(previousOneDelete + arr[i],
                previousNoDelete);
```

---

## Why do we save previous values?

Before updating the current states, we store

```cpp
previousNoDelete = noDelete;
previousOneDelete = oneDelete;
```

because after updating `noDelete`, its previous value would be lost.

`oneDelete` depends on the **old** value of `noDelete`, not the updated one.

---

## Algorithm

1. Initialize

```cpp
noDelete = arr[0]
oneDelete = 0
```

2. Iterate through the array.

3. Save previous values.

4. Update

```cpp
noDelete = max(previousNoDelete + arr[i], arr[i]);

oneDelete = max(previousOneDelete + arr[i],
                previousNoDelete);
```

5. Update the global answer.

---

## Dry Run

Array

```
[1, -2, 0, 3]
```

| Index | Value | previousNoDelete | previousOneDelete | noDelete | oneDelete | Answer |
|------:|------:|-----------------:|------------------:|---------:|----------:|-------:|
| 0 | 1 | - | - | 1 | 0 | 1 |
| 1 | -2 | 1 | 0 | -1 | 1 | 1 |
| 2 | 0 | -1 | 1 | 0 | 1 | 1 |
| 3 | 3 | 0 | 1 | 3 | 4 | 4 |

Final Answer = **4**

Subarray:

```
[1, -2, 0, 3]
```

Delete

```
-2
```

Remaining subarray

```
[1, 0, 3]
```

Sum = **4**

---

## Complexity

### Time Complexity

```
O(n)
```

Only one traversal of the array.

### Space Complexity

```
O(1)
```

Only a few variables are used.

---


## Key Takeaways

- This problem is an extension of **Kadane's Algorithm**.
- `noDelete` behaves exactly like Kadane's state.
- `oneDelete` keeps track of the best subarray ending at the current index after one deletion.
- The two transitions for `oneDelete` are:
  - Continue after a previous deletion.
  - Delete the current element.
- `previousNoDelete` and `previousOneDelete` are temporary copies that preserve the values from the previous index before updating the current states.
