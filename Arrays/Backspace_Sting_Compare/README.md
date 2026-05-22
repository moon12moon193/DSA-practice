# Backspace String Compare — LeetCode 844

## 📌 Problem Statement

Given two strings `s` and `t`, return `true` if they are equal when both are typed into empty text editors.

The character:


'#'


means a backspace character.

---

## 🧠 Example

### Example 1


Input:
s = "ab#c"
t = "ad#c"

Output:
true


### Explanation


"ab#c"  -> "ac"
"ad#c"  -> "ac"


Both become equal.

---

# 💡 Approach Used

This solution simulates typing into a text editor.

We create a helper function:


removeCharacters()


which processes the string and removes characters whenever `#` appears.

Then both processed strings are compared.

---

# ⚙️ Algorithm

## Step 1: Process the String

Traverse the string:

* If character is a lowercase letter:

  * store it
* If character is `#`:

  * remove the previously stored character (if available)

This behaves exactly like backspace typing.

---

## Step 2: Compare Processed Strings

After processing both strings:

* If lengths differ → return `false`
* Otherwise compare character by character

---

# ✅ Time Complexity

## removeCharacters()

Each character is visited once.


Time Complexity: O(n)


---

## EqualStrs()

Compares all characters once.


Time Complexity: O(n)


---

## Overall Complexity


Time Complexity: O(n + m)


where:

* `n` = length of string `s`
* `m` = length of string `t`

---

# ✅ Space Complexity

Extra processed strings are created.


Space Complexity: O(n + m)


---

# 🔍 Dry Run

## Input


s = "ab#c"
t = "ad#c"


---

## Processing `s`

| Character | Action   | Result |
| --------- | -------- | ------ |
| a         | add      | a      |
| b         | add      | ab     |
| #         | remove b | a      |
| c         | add      | ac     |

Final:


ac


---

## Processing `t`

| Character | Action   | Result |
| --------- | -------- | ------ |
| a         | add      | a      |
| d         | add      | ad     |
| #         | remove d | a      |
| c         | add      | ac     |

Final:


ac


---

## Comparison


ac == ac


Return:


true


---




# 🎯 Key Learning

This problem teaches:

* String simulation
* Two-pointer style processing
* In-place modification
* Handling backspace operations efficiently

---




