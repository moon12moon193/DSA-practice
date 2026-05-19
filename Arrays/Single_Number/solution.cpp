class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        if (nums.size() == 1) {
            return nums[i];
        }
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
        
        for (int i = 1; i < nums.size() ; i++) {
             if (i == nums.size() - 1 && nums[i] != nums[i - 1]) {
            return nums[i];
        }
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
