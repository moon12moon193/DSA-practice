# Recursion & Backtracking

This folder contains my practice and learning progress for **Recursion and Backtracking** in Data Structures and Algorithms.

The goal of this section is to understand how a problem can be broken into smaller instances of itself, how recursive calls work internally, and how backtracking can systematically explore and undo choices.

---

## Topics Covered

### 1. Recursion Fundamentals

* What is recursion?
* Recursive functions
* Base cases
* Recursive cases
* Call stack
* Recursive function execution
* How recursive calls return
* Stack memory in recursion
* Identifying recursive patterns

---

### 2. Base Case

The **base case** is the condition that stops recursion.

Without a proper base case, the function can continue calling itself indefinitely and cause stack overflow.

General structure:

```cpp
void solve(int n) {

    // Base case
    if (n == 0) {
        return;
    }

    // Recursive call
    solve(n - 1);
}
```

The base case answers:

> When should recursion stop?

---

### 3. Recursive Case

The recursive case is the part where the function calls itself with a smaller or modified input.

```cpp
solve(n - 1);
```

A recursive solution usually contains:

```text
Base Case
    ↓
Make a Choice / Perform Work
    ↓
Recursive Call
    ↓
Return
```

---

## 4. How Recursion Works Internally

Every recursive call creates a new **stack frame**.

For example:

```cpp
solve(3);
```

may create:

```text
solve(3)
   ↓
solve(2)
   ↓
solve(1)
   ↓
solve(0)
```

The calls continue until the base case is reached.

Then the functions return in reverse order:

```text
solve(0)
   ↑
solve(1)
   ↑
solve(2)
   ↑
solve(3)
```

Understanding this process is extremely important for solving recursive problems.

---

## 5. Recursion Tree

Some recursive problems generate multiple recursive calls.

For example:

```cpp
solve(n - 1);
solve(n - 2);
```

This creates a recursion tree:

```text
             solve(n)
             /      \
       solve(n-1)  solve(n-2)
        /    \       /    \
       ...   ...   ...    ...
```

Recursion trees help visualize:

* Number of recursive calls
* Repeated work
* Time complexity
* Different possible paths

---

## 6. Types of Recursion

Important recursion patterns include:

### Single Recursion

One recursive call:

```cpp
solve(n - 1);
```

### Multiple Recursion

More than one recursive call:

```cpp
solve(n - 1);
solve(n - 2);
```

### Tail Recursion

The recursive call is the final operation.

```cpp
solve(n - 1);
```

### Head Recursion

The recursive call happens before the main processing.

```cpp
solve(n - 1);
cout << n;
```

Understanding these patterns helps in recognizing recursive structures.

---

# Backtracking

Backtracking is an extension of recursion where we:

1. Make a choice.
2. Explore that choice.
3. Undo the choice.
4. Try another choice.

The general pattern is:

```text
Choose
   ↓
Explore
   ↓
Undo
   ↓
Choose another option
```

---

## 7. Basic Backtracking Pattern

A typical backtracking structure looks like:

```cpp
void backtrack(...) {

    // Base case
    if (...) {
        // Store/process answer
        return;
    }

    for (...) {

        // Make a choice

        // Explore
        backtrack(...);

        // Undo the choice
    }
}
```

The most important part is the **undo step**.

---

## 8. Choice → Explore → Undo

Consider a decision where we can either include or exclude something.

The recursion may look like:

```text
                 Start
                /     \
            Choose    Don't Choose
              /          \
           Explore      Explore
              |            |
            Undo         Undo
```

Backtracking systematically explores these possibilities.

---

# 9. State in Backtracking

A recursive/backtracking function usually maintains some state.

The state can contain:

* Current index
* Current path
* Current sum
* Current selection
* Current position
* Used elements
* Remaining choices

Example:

```cpp
void backtrack(vector<int>& nums,
               vector<int>& path,
               int index) {
    
    ...
}
```

Understanding what each parameter represents is essential.

---

# 10. Decision Tree

Backtracking problems can often be visualized as a **decision tree**.

For example:

```text
                    Start
                  /       \
               Choice 1   Choice 2
                /   \       /   \
             ...    ...   ...   ...
```

Each branch represents a different decision.

The algorithm explores each valid branch and backtracks whenever necessary.

---

# 11. Common Backtracking Techniques

Important techniques to practice include:

### Include / Exclude

At every step:

```text
Include
Exclude
```

This commonly produces a binary decision tree.

---

### For Loop + Recursion

Choose one option from several available choices:

```cpp
for (int i = start; i < n; i++) {

    path.push_back(...);

    backtrack(...);

    path.pop_back();
}
```

---

### Used Array

Track which elements have already been selected:

```cpp
vector<bool> used(n, false);
```

Before choosing:

```cpp
used[i] = true;
```

After recursion:

```cpp
used[i] = false;
```

---

### Swap-Based Backtracking

Sometimes choices can be generated by swapping elements:

```cpp
swap(nums[index], nums[i]);

backtrack(index + 1);

swap(nums[index], nums[i]);
```

The second swap restores the original state.

---

# 12. Backtracking Template

A general template:

```cpp
void backtrack(...) {

    if (baseCondition) {
        // Store answer
        return;
    }

    for (...) {

        if (invalidChoice) {
            continue;
        }

        // Make choice
        path.push_back(...);

        // Explore
        backtrack(...);

        // Undo choice
        path.pop_back();
    }
}
```

The three most important parts are:

```text
Make Choice
     ↓
Recursive Call
     ↓
Undo Choice
```

---

# 13. Recursion vs Backtracking

| Recursion                                     | Backtracking                         |
| --------------------------------------------- | ------------------------------------ |
| Function calls itself                         | Uses recursion to explore choices    |
| Mainly breaks a problem into smaller problems | Explores multiple possible solutions |
| May follow one recursive path                 | Usually explores multiple branches   |
| Does not always require undoing               | Usually requires undoing choices     |
| Can be simple                                 | Often uses a decision tree           |

Backtracking is therefore commonly implemented **using recursion**, but not every recursive algorithm is backtracking.

---

# 14. Base Cases in Backtracking

A base case determines when a complete solution has been constructed.

For example:

```cpp
if (index == nums.size()) {
    result.push_back(path);
    return;
}
```

At this point, recursion stops for that branch.

The algorithm then returns to the previous level and tries another choice.

---

# 15. Pruning

**Pruning** means stopping a branch early when we know it cannot produce a valid solution.

Instead of exploring:

```text
Start
 ├── Valid
 │    ├── Valid
 │    └── Valid
 │
 └── Invalid
      ├── ❌
      └── ❌
```

we immediately stop exploring the invalid branch.

```cpp
if (invalid) {
    return;
}
```

Pruning can significantly improve backtracking performance.

---

# 16. Important Questions to Ask

When solving a recursion problem, ask:

1. What is the base case?
2. What is the recursive case?
3. What is getting smaller or changing?
4. What should each recursive call represent?
5. What happens when the function returns?

For backtracking, additionally ask:

6. What choices do I have?
7. Which choices are valid?
8. What state changes after making a choice?
9. What needs to be undone?
10. Can I prune invalid branches?

---

# 17. Complexity

Recursion and backtracking complexity depends heavily on the number of branches.

If each level has approximately `k` choices and there are `n` levels, the recursion tree can contain approximately:

```text
O(k^n)
```

states.

However, pruning, constraints, and duplicate handling can significantly reduce the actual number of explored states.

Space complexity also includes the **recursion stack**.

---

# 18. Common Mistakes

While practicing recursion and backtracking, watch for:

* Missing base case
* Incorrect base case
* Infinite recursion
* Not moving toward the base case
* Incorrect recursive parameters
* Forgetting to undo a choice
* Modifying shared state incorrectly
* Forgetting to restore an array/vector
* Adding incomplete states to the answer
* Not pruning impossible branches
* Confusing recursion with backtracking
* Stack overflow due to excessive recursion depth

---

# 19. Learning Strategy

For each recursion problem:

```text
1. Identify the base case
        ↓
2. Identify the recursive case
        ↓
3. Understand the changing state
        ↓
4. Draw the recursion tree
        ↓
5. Write the recursive function
        ↓
6. Dry run manually
        ↓
7. Analyze time and space complexity
```

For backtracking:

```text
1. Identify all possible choices
        ↓
2. Choose one option
        ↓
3. Explore recursively
        ↓
4. Undo the choice
        ↓
5. Try the next option
        ↓
6. Prune invalid branches
```

---

# Key Takeaways

* Recursion solves a problem by calling the same function on a smaller or modified state.
* Every recursive solution needs a well-defined **base case**.
* Recursive calls are stored in the **call stack**.
* A recursion tree helps visualize multiple recursive calls.
* Backtracking uses recursion to explore different choices.
* The fundamental backtracking pattern is:

```text
Choose → Explore → Undo
```

* **Pruning** prevents unnecessary exploration.
* Always understand the state being passed between recursive calls.
* Drawing the recursion tree and performing a dry run are excellent ways to understand recursion deeply.
* Recursion and backtracking are important foundations for more advanced DSA topics such as tree traversal, graph traversal, dynamic programming, and constraint-solving.
