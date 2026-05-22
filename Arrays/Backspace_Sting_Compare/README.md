# Backspace String Compare

## Problem Statement

Given two strings `s` and `t` containing:

* lowercase letters
* `#` characters

The `#` symbol represents a:


backspace


which removes the previous valid character.

Return:

* `true` if both processed strings are equal
* `false` otherwise

---

# Example

## Input


s = "ab##"
t = "c#d#"


---

## Processing `s`


"a"
"ab"
"a"
""


Final string:


""


---

## Processing `t`


"c"
""
"d"
""


Final string:


""


---

## Output


true


because both processed strings are equal.

---

# Approach

The solution uses:


in-place string processing


to simulate backspaces efficiently.

---

# removeCharacters() Function

This function:

* traverses the string
* keeps valid characters
* removes previous characters when `#` appears
* resizes the string to valid length

---

# Core Idea

A pointer `j` tracks:




---

## If character is alphabet

Store it at:


str[j]


then increment `j`.

---

## If character is `#`

Move `j` backward:


logical deletion of previous valid character


---

# Dry Run

## Input


"ab#c"


---

| Character | Action   | Valid String |
| --------- | -------- | ------------ |
| a         | keep     | a            |
| b         | keep     | ab           |
| #         | remove b | a            |
| c         | keep     | ac           |

---

Final string:


"ac"


---

# EqualStrs() Function

This function:

* first checks lengths
* then compares characters one-by-one from end

If any mismatch occurs:


return false


Otherwise:


return true


---

# Time Complexity

## removeCharacters()

Each string traversed once:


O(n)


---

## EqualStrs()

String comparison:


O(n)


---

# Overall Time Complexity


O(n + m)


where:

* `n` = length of first string
* `m` = length of second string

---

# Space Complexity

In-place processing uses:



extra auxiliary space.

---

# Code


class Solution {
public:
string removeCharacters(string str){
    int j=0;

    for(int i=0;i<str.length();i++){
        if(i==0 && str[i]=='#'){
            continue;
        }
        if(str[i]>='a' && str[i]<='z'){
            str[j]=str[i];
            j++;
        }else{
            if(j>0){
                j=j-1;
            }
        }
    }
    str.resize(j);
    return str;
}


bool EqualStrs(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }else{
        int i=str1.length()-1;
        int j=str2.length()-1;
        while(i>=0 && j>=0){
            if(str1[i]!=str2[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
}
    bool backspaceCompare(string s, string t) {
        string str1=removeCharacters(s);
        string str2=removeCharacters(t);
        bool ans=EqualStrs(str1,str2);
        return ans;
        
    }

