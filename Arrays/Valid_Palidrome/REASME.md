# Valid Palindrome (LeetCode 125) — Solution README

## 📌 Problem Statement

Given a string `s`, determine if it is a palindrome after:

* Ignoring non-alphanumeric characters
* Converting uppercase letters to lowercase
* Considering only letters (A–Z, a–z) and digits (0–9)

A string is a palindrome if it reads the same forward and backward.

---

## 💡 Approach Used

This solution follows a **two-step approach**:

### 1. Filtering Step (In-place)

We traverse the string and keep only valid characters:

* Letters (`A-Z`, `a-z`)
* Digits (`0-9`)

All valid characters are stored back into the same string using index `j`.

We also convert uppercase letters to lowercase using:


tolower()


---

### 2. Resize the String

After filtering, we resize the string to keep only valid characters:


s.resize(j);


---

### 3. Palindrome Check

We use a simple two-pointer technique:

* `i` starts from beginning
* `j` starts from end
* Compare characters until they meet

If any mismatch occurs → return `false`
Otherwise → return `true`

---

## ⚙️ Time Complexity

* Filtering: O(n)
* Palindrome check: O(n)
  👉 Total: **O(n)**

## 🧠 Space Complexity

* O(1) extra space (modifying string in-place)

---


## 🧾 Summary

* Cleaned string using in-place filtering
* Converted letters to lowercase
* Checked palindrome using two pointers
* Efficient O(n) solution

---

## 👨‍💻 Author Logic

This solution avoids extra space by modifying the input string directly and then verifying palindrome properties on the cleaned string.
