# 3Sum — LeetCode 15

## 📌 Problem Statement

Given an integer array `nums`, return all unique triplets:


[nums[i], nums[j], nums[k]]


such that:


nums[i] + nums[j] + nums[k] == 0


Conditions:

* `i`, `j`, and `k` must be different indexes
* Output must not contain duplicate triplets

---

# 💡 Approach Used

This solution uses:

* Sorting
* Fixed pointer
* Two-pointer technique
* Duplicate skipping

---

# ⚙️ Algorithm Explanation

## 1. Sort the Array


sort(nums.begin(), nums.end());


Sorting helps:

* apply two-pointer technique
* skip duplicate triplets efficiently

Example:


[-1,0,1,2,-1,-4]


becomes:


[-4,-1,-1,0,1,2]


---

# 2. Fix One Element

Use loop variable `i` as the first element of triplet.


for(int i=0; i<nums.size()-2; i++)


---

# 3. Skip Duplicate Fixed Values


if(i > 0 && nums[i] == nums[i-1])
{
    continue;
}


If current value equals previous value:

* skip current iteration
* avoids duplicate triplets

---

# 4. Use Two Pointers

For every fixed `i`:


left = i + 1
right = nums.size() - 1


Now search for remaining two values.

---

# 5. Check Sum

## If sum becomes 0

Valid triplet found:

nums[i] + nums[left] + nums[right] == 0


Store triplet in result.

Then:

* move left forward
* move right backward

---

## If sum < 0

Need larger value.


left++


---

## If sum > 0

Need smaller value.


right--


---

# 6. Skip Duplicate Left and Right Values

After finding valid triplet:

```cpp id="h7i8j9"
while(nums[left] == nums[left-1])
```

and


while(nums[right] == nums[right+1])


skip repeated values to avoid duplicate triplets.

---

# ✅ Example

Input:


[-1,0,1,2,-1,-4]


Sorted:


[-4,-1,-1,0,1,2]


Output:

[
 [-1,-1,2],
 [-1,0,1]
]


---

# 🧠 Time Complexity

## Sorting

O(n log n)


## Outer loop

O(n)


## Two-pointer traversal


O(n)


Overall:

# ✅


O(n²)


---

# 💾 Space Complexity

Ignoring output array:

# ✅


O(1)

Result vector storing triplets is not counted as extra auxiliary space.

---

# 🔑 Important Concepts Learned

* Sorting arrays
* Two-pointer technique
* Duplicate handling
* Nested loop optimization
* Efficient triplet searching

---

# 🚨 Key Insight

Duplicate triplets are removed by:

* skipping repeated fixed values
* skipping repeated left/right values

This avoids expensive searching using `find()` and keeps solution optimal.
