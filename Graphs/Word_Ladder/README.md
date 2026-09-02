# Word Ladder — BFS

## Problem

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, find the length of the **shortest transformation sequence** from `beginWord` to `endWord`.

A transformation follows these rules:

1. Only **one character** can be changed at a time.
2. Every intermediate word must exist in `wordList`.
3. The transformation must start from `beginWord`.
4. The transformation must end at `endWord`.

If no transformation is possible, return `0`.

### Example

```text
beginWord = "hit"
endWord = "cog"

wordList = ["hot","dot","dog","lot","log","cog"]
```

One shortest transformation is:

```text
hit → hot → dot → dog → cog
```

Therefore:

```text
Answer = 5
```

---

## Approach

This problem can be solved using **Breadth-First Search (BFS)**.

Why BFS?

We need the **shortest path** from `beginWord` to `endWord`.

Each word can be considered a node, and an edge exists between two words if they differ by exactly one character.

For example:

```text
hit
 |
hot
 |
dot
 |
dog
 |
cog
```

BFS explores the transformation levels one by one:

```text
Level 1 → hit
Level 2 → hot
Level 3 → dot
Level 4 → dog
Level 5 → cog
```

Therefore, the first time we reach `endWord`, we have found the shortest transformation sequence.

---

## Data Structures

### 1. `unordered_map`

```cpp
unordered_map<string, int> f;
```

This stores all words from `wordList`.

The map is also used as a **visited/unvisited set**.

```cpp
f[wordList[i]] = 1;
```

When a word is used, we remove it:

```cpp
f.erase(word);
```

This prevents visiting the same word multiple times.

---

### 2. Queue

```cpp
queue<pair<string,int>> q;
```

The queue stores:

```text
word
distance
```

For example:

```cpp
q.push({"hit", 1});
```

means:

```text
Current word = hit
Transformation length = 1
```

---

## Algorithm

### Step 1 — Store all words

```cpp
unordered_map<string, int> f;

for(int i = 0; i < n; i++) {
    f[wordList[i]] = 1;
}
```

---

### Step 2 — Check whether `endWord` exists

If `endWord` is not present in the dictionary, transformation is impossible.

```cpp
if(f.find(endWord) == f.end()) {
    return 0;
}
```

---

### Step 3 — Push `beginWord`

```cpp
queue<pair<string,int>> q;

q.push({beginWord, 1});
```

The initial transformation length is `1` because the sequence includes `beginWord`.

---

### Step 4 — Mark `beginWord` as visited

```cpp
f.erase(beginWord);
```

This prevents us from coming back to `beginWord`.

---

### Step 5 — Perform BFS

```cpp
while(!q.empty()) {
    pair<string,int> p = q.front();
    q.pop();

    string word = p.first;
    int val = p.second;
```

We take the current word and its transformation length.

---

### Step 6 — Check if we reached the destination

```cpp
if(word == endWord) {
    return val;
}
```

Because BFS explores nodes level by level, the first time we reach `endWord`, it is guaranteed to be the shortest transformation.

---

## Generating Neighboring Words

For every character in the current word, try replacing it with every lowercase English letter.

```cpp
for(int i = 0; i < word.size(); i++) {

    int character = word[i];

    for(int j = 97; j <= 122; j++) {
```

ASCII values:

```text
97 → a
98 → b
99 → c
...
122 → z
```

So this loop tries every possible lowercase character.

---

### Replace the character

```cpp
word[i] = j;
```

For example:

```text
hot
```

Changing the first character can produce:

```text
aot
bot
cot
dot
...
zot
```

Only words that exist in `f` are valid transformations.

---

### Check whether the generated word exists

```cpp
if(f.find(word) != f.end()) {
    q.push({word, val + 1});
    f.erase(word);
}
```

If the generated word exists:

1. Add it to the queue.
2. Increase the transformation length.
3. Remove it from the map so it isn't visited again.

---

## Restore the Original Character

After trying all characters at position `i`, restore the original character:

```cpp
word[i] = character;
```

This is important because we need to modify the next character of the **original word**.

---

## Complete Code

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        int n = wordList.size();

        unordered_map<string, int> f;

        // Store all words
        for(int i = 0; i < n; i++) {
            f[wordList[i]] = 1;
        }

        // Add beginWord if it is not present
        if(f.find(beginWord) == f.end()) {
            f[beginWord] = 1;
        }

        // If endWord does not exist, transformation is impossible
        if(f.find(endWord) == f.end()) {
            return 0;
        }

        // BFS queue: {word, transformation length}
        queue<pair<string,int>> q;

        q.push({beginWord, 1});

        // Mark beginWord as visited
        f.erase(beginWord);

        while(!q.empty()) {

            pair<string,int> p = q.front();
            q.pop();

            string word = p.first;
            int val = p.second;

            // Destination reached
            if(word == endWord) {
                return val;
            }

            // Try changing every character
            for(int i = 0; i < word.size(); i++) {

                int character = word[i];

                // Try a-z
                for(int j = 97; j <= 122; j++) {

                    if(j == character) {
                        continue;
                    }

                    word[i] = j;

                    // Valid and unvisited word
                    if(f.find(word) != f.end()) {

                        q.push({word, val + 1});

                        // Mark visited
                        f.erase(word);
                    }
                }

                // Restore original character
                word[i] = character;
            }
        }

        return 0;
    }
};
```

---

## Cleaner Character Loop

Instead of using ASCII values:

```cpp
for(int j = 97; j <= 122; j++)
```

you can write:

```cpp
for(char c = 'a'; c <= 'z'; c++) {
```

Then:

```cpp
word[i] = c;
```

This is more readable:

```cpp
for(char c = 'a'; c <= 'z'; c++) {

    if(c == word[i]) {
        continue;
    }

    word[i] = c;

    if(f.find(word) != f.end()) {
        q.push({word, val + 1});
        f.erase(word);
    }
}
```

---

## Why Do We Erase Words?

Suppose:

```text
hit → hot
```

Once `hot` is discovered, we do:

```cpp
f.erase("hot");
```

This means `hot` will never be inserted into the queue again.

Without this, the same word could be reached through multiple paths:

```text
hit → hot
       ↑
other → hot
```

That would cause unnecessary processing.

Therefore, the `unordered_map` is effectively being used as a **visited set**.

---

## Time Complexity

Let:

* `N` = number of words in `wordList`
* `L` = length of each word

For every visited word, we try:

```text
L positions × 26 characters
```

So approximately:

```text
O(N × L × 26)
```

Since `26` is constant:

```text
O(N × L)
```

The `unordered_map` lookup is approximately `O(1)` on average.

### Space Complexity

The map stores up to `N` words:

```text
O(N)
```

The BFS queue can also contain up to `N` words:

```text
O(N)
```

Therefore:

```text
Space Complexity = O(N)
```

---

## Key DSA Pattern

This problem teaches an important BFS pattern:

```text
Shortest path in an unweighted graph
            ↓
          BFS
            ↓
Generate valid neighbors
            ↓
Mark visited
            ↓
Store distance
```

The important idea is that the graph does **not** need to be explicitly constructed.

Instead, we dynamically generate neighboring words by changing one character at a time.

### Pattern to remember

```cpp
queue<pair<State, Distance>> q;

q.push({start, 1});

while(!q.empty()) {

    State current = q.front();
    q.pop();

    for(each possible next state) {

        if(valid && not visited) {

            q.push({next, distance + 1});
            mark visited;
        }
    }
}
```

This pattern is useful for many **shortest-path BFS problems** where states can be generated dynamically.
