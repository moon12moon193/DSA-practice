# Recursion & Backtracking — Generating Combinations

## Problem

Given a string containing digits from `2` to `9`, generate all possible letter combinations that the digits can represent.

Each digit maps to a group of letters:

```text
2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz
```

For example, if:

```text
digits = "23"
```

the possible combinations are:

```text
ad
ae
af
bd
be
bf
cd
ce
cf
```

---

# Approach

This solution uses:

* **Recursion**
* **Backtracking**
* **Hash Map**
* **String construction**

The basic idea is:

1. Take one digit.
2. Get all letters associated with that digit.
3. Choose one letter.
4. Recursively process the next digit.
5. Remove the chosen letter using backtracking.
6. Try the next letter.

The general pattern is:

```text
Choose
   ↓
Recursive Call
   ↓
Undo Choice
```

---

# Hash Map

The first step is creating a mapping between each digit and its possible letters.

```cpp
unordered_map<char, string> f;

f['2'] = "abc";
f['3'] = "def";
f['4'] = "ghi";
f['5'] = "jkl";
f['6'] = "mno";
f['7'] = "pqrs";
f['8'] = "tuv";
f['9'] = "wxyz";
```

For example:

```cpp
f['2']
```

returns:

```text
"abc"
```

and:

```cpp
f['7']
```

returns:

```text
"pqrs"
```

---

# Recursive Function

The recursive function is:

```cpp
fun(index, digits, temp, result, f)
```

Each parameter has a specific purpose.

### `index`

Represents which digit we are currently processing.

### `digits`

The original input string.

### `temp`

Stores the current combination being constructed.

### `result`

Stores all completed combinations.

### `f`

Stores the digit-to-letter mapping.

---

# Base Case

The recursion stops when all digits have been processed.

```cpp
if(index == n){
    result.push_back(temp);
    return;
}
```

Suppose:

```text
digits = "23"
```

When:

```text
index = 2
```

both digits have been processed.

If:

```text
temp = "ad"
```

then `"ad"` is a complete combination, so it is added to `result`.

---

# Getting Letters for Current Digit

Inside the recursive function:

```cpp
string t = f[digits[index]];
```

Suppose:

```text
digits = "23"
index = 0
```

Then:

```cpp
digits[index] = '2'
```

and:

```cpp
f['2'] = "abc"
```

Therefore:

```text
t = "abc"
```

---

# Choosing a Letter

We iterate through all letters available for the current digit:

```cpp
for(int i = 0; i < t.length(); i++){
    temp.push_back(t[i]);

    fun(index + 1, digits, temp, result, f);

    temp.pop_back();
}
```

For digit `2`, the choices are:

```text
a
b
c
```

The first choice is:

```text
temp = "a"
```

Then recursion moves to the next digit.

---

# Backtracking

The most important part is:

```cpp
temp.pop_back();
```

The sequence is:

```text
temp.push_back(...)
        ↓
   Recursive Call
        ↓
temp.pop_back()
```

This means:

### 1. Make a choice

```cpp
temp.push_back(t[i]);
```

### 2. Explore the choice

```cpp
fun(index + 1, ...);
```

### 3. Undo the choice

```cpp
temp.pop_back();
```

This allows the program to reuse `temp` for another combination.

---

# Recursion Tree

Consider:

```text
digits = "23"
```

The recursion tree looks like:

```text
                    ""
                 /   |   \
                a    b    c
              / | \ /|\ /|\
             ad ae af bd be bf cd ce cf
```

The first digit `2` gives:

```text
a
b
c
```

For each of these choices, digit `3` gives:

```text
d
e
f
```

Therefore:

```text
a → ad, ae, af
b → bd, be, bf
c → cd, ce, cf
```

---

# Detailed Dry Run

Suppose:

```text
digits = "23"
```

Initially:

```text
index = 0
temp = ""
```

### Processing `2`

The mapping gives:

```text
abc
```

Choose `a`:

```text
temp = "a"
```

Call:

```cpp
fun(1, ...)
```

---

### Processing `3`

The mapping gives:

```text
def
```

Choose `d`:

```text
temp = "ad"
```

Now:

```text
index = 2
```

Base case is reached.

Store:

```text
ad
```

Then backtrack:

```text
temp = "a"
```

Next choose `e`:

```text
temp = "ae"
```

Store:

```text
ae
```

Backtrack again.

Then choose `f`:

```text
temp = "af"
```

Store:

```text
af
```

After all letters for `3` are processed, backtrack again:

```text
temp = ""
```

Then choose `b`.

This process continues until all combinations are generated.

---

# C++ Solution

```cpp
class Solution {
public:

    void fun(
        int index,
        string& digits,
        string& temp,
        vector<string>& result,
        unordered_map<char, string>& f
    ) {

        int n = digits.length();

        // Base case
        if (index == n) {
            result.push_back(temp);
            return;
        }

        // Get letters corresponding to current digit
        string t = f[digits[index]];

        // Try every possible letter
        for (int i = 0; i < t.length(); i++) {

            // Choose
            temp.push_back(t[i]);

            // Explore
            fun(index + 1, digits, temp, result, f);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> f;

        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        vector<string> result;
        string temp;

        fun(0, digits, temp, result, f);

        return result;
    }
};
```

---

# Important Edge Case

If the input is empty:

```text
digits = ""
```

there are no combinations to generate.

So it is better to handle it before starting recursion:

```cpp
if(digits.empty()){
    return {};
}
```

For example:

```cpp
vector<string> letterCombinations(string digits) {

    if(digits.empty()){
        return {};
    }

    // remaining code...
}
```

---

# Complexity Analysis

Let:

```text
n = number of digits
```

Each digit can have up to `4` possible letters.

Therefore, the maximum number of combinations is:

```text
4^n
```

Each combination has length `n`.

### Time Complexity

```text
O(4^n × n)
```

The `n` factor comes from constructing/storing each combination.

### Space Complexity

The result itself requires:

```text
O(4^n × n)
```

because all combinations are stored.

The recursion depth is:

```text
O(n)
```

and `temp` also uses:

```text
O(n)
```

---

# Key Takeaways

* Use a **hash map** to store digit-to-letter mappings.
* `index` tells us which digit we are currently processing.
* `temp` stores the current combination.
* Recursion moves to the next digit.
* `push_back()` makes a choice.
* Recursive call explores that choice.
* `pop_back()` undoes the choice.
* The base case is reached when all digits have been processed.
* This follows the fundamental backtracking pattern:

```text
Choose → Explore → Undo
```

* The recursion tree represents all possible combinations.
* When each digit has up to 4 choices, the number of combinations can grow as `4^n`.
