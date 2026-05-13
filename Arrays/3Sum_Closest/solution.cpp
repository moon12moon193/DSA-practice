class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mini = INT16_MAX;
        int ans = 0;
        bool IsChange = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int value = abs(sum - target);
                if (value < mini) {
                    mini = value;
                    IsChange = true;
                }

                if (IsChange == true) {
                    ans = sum;
                }
                IsChange = false;
                if (sum == target) {
                    left++;
                    right--;
                    while (left > 0 && left < nums.size() &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right < nums.size() - 1 && right >= 0 &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                    while (left > 0 && left < nums.size() &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }
                } else {
                    right--;
                    while (right < nums.size() - 1 && right >= 0 &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
