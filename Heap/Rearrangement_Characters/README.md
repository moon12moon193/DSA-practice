# Reorganize String (LeetCode 767)

## Problem

Given a string `s`, rearrange its characters so that **no two adjacent characters are the same**.

Return **any valid rearranged string**.

If it is impossible to rearrange the string, return an empty string `""`.

---

## Example 1

**Input**

```cpp
s = "aab"
```

**Output**

```cpp
"aba"
```

---

## Example 2

**Input**

```cpp
s = "aaab"
```

**Output**

```cpp
""
```

### Explanation

The character `'a'` appears too many times, making it impossible to arrange the string without placing two `'a'` characters next to each other.

---

# Intuition

The character with the **highest remaining frequency** should always be placed first.

A **Max Heap** is ideal because it always gives the character with the highest frequency.

However, before placing a character, we must ensure it is **different from the last character** already placed in the result.

If the top character would create two adjacent equal characters:

- Use the second most frequent character instead.
- Reinsert the skipped character back into the heap.

This greedy strategy always tries to place the most frequent valid character.

---

# Approach

## Step 1: Count Character Frequencies

Use a HashMap to count how many times each character appears.

```cpp
unordered_map<char, int> f;

for(char ch : s)
{
    f[ch]++;
}
```

---

## Step 2: Build a Max Heap

Store pairs of

```text
(frequency, character)
```

The custom comparator keeps the character with the **highest frequency** at the top.

```cpp
priority_queue<pair<int,char>,
               vector<pair<int,char>>,
               cmp> pq;
```

---

## Step 3: Process the Heap

Repeat until the heap becomes empty.

Remove the most frequent character.

### Case 1

If

- the result is empty, or
- the last character in the result is different,

append the character.

Decrease its frequency.

If it still has remaining occurrences,

push it back into the heap.

---

### Case 2

If the top character is the same as the last character in the result,

check whether another character exists.

If the heap is empty,

return

```cpp
""
```

because no valid arrangement is possible.

Otherwise,

remove the second most frequent character.

Append it to the result.

Decrease its frequency.

Push it back if needed.

Finally,

push the skipped character back into the heap.

---

## Step 4: Return the Result

After all characters are placed,

return the constructed string.

---

# Dry Run

### Input

```text
s = "aab"
```

---

### Frequency Map

```text
a → 2
b → 1
```

---

### Initial Heap

```text
(2,a)
(1,b)
```

---

### Iteration 1

Top:

```text
(2,a)
```

Result:

```text
"a"
```

Remaining frequency:

```text
a → 1
```

Push back

```text
(1,a)
```

Heap:

```text
(1,a)
(1,b)
```

---

### Iteration 2

Top:

```text
(1,a)
```

The last character in the result is also

```text
'a'
```

So choose the next character.

Pop

```text
(1,b)
```

Result:

```text
"ab"
```

Remaining frequency:

```text
0
```

Push back the skipped character

```text
(1,a)
```

---

### Iteration 3

Top:

```text
(1,a)
```

Last character:

```text
'b'
```

Append

```text
'a'
```

Result:

```text
"aba"
```

Heap becomes empty.

Return

```text
"aba"
```

---

# Why Use a Max Heap?

The most frequent character has the highest chance of causing adjacent duplicates if it is delayed.

A Max Heap ensures that:

- The character with the highest remaining frequency is always considered first.
- If it cannot be placed immediately, the next best option is used.
- The skipped character is preserved by pushing it back into the heap.

This greedy approach produces a valid arrangement whenever one exists.

---

# Complexity Analysis

### Time Complexity

Building the frequency map:

```text
O(n)
```

Each heap insertion or removal takes:

```text
O(log k)
```

where `k` is the number of distinct characters.

Overall:

```text
O(n log k)
```

Since lowercase English letters are limited, `k` is at most `26`, making the solution effectively linear for this problem.

---

### Space Complexity

Frequency map:

```text
O(k)
```

Heap:

```text
O(k)
```

Result string:

```text
O(n)
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
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {

        priority_queue<pair<int, char>,
                       vector<pair<int, char>>,
                       cmp> pq;

        unordered_map<char, int> f;

        for (char ch : s) {
            f[ch]++;
        }

        for (auto elem : f) {
            pq.push({elem.second, elem.first});
        }

        string res = "";
        int seat = 0;

        while (!pq.empty()) {

            pair<int, char> p = pq.top();
            pq.pop();

            int freq = p.first;
            char ch = p.second;

            if (res.empty() || res[seat - 1] != ch) {

                res += ch;
                freq--;

                if (freq > 0) {
                    pq.push({freq, ch});
                }

            } else {

                if (pq.empty()) {
                    return "";
                }

                pair<int, char> p2 = pq.top();
                pq.pop();

                int freq2 = p2.first;
                char ch2 = p2.second;

                res += ch2;
                freq2--;

                if (freq2 > 0) {
                    pq.push({freq2, ch2});
                }

                pq.push({freq, ch});
            }

            seat++;
        }

        return res;
    }
};
```

---

# Key Takeaways

- Count character frequencies using a **HashMap**.
- Use a **Max Heap** to always select the character with the highest remaining frequency.
- Never place the same character adjacent to itself.
- If the most frequent character cannot be used, temporarily use the second most frequent character and reinsert the skipped one.
- If no alternative character exists when needed, return an empty string because a valid arrangement is impossible.
- This problem is a classic example of combining **Greedy + Heap + HashMap** to efficiently construct a valid solution.
