class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       
        int maxSum = nums[0];
        int minSum = nums[0];
        int res = nums[0];
        if(nums.size()==1){
           return abs(res) ;
        }
        for (int i = 1; i < nums.size(); i++) {
            int v1 = maxSum + nums[i];
            int v2 = minSum + nums[i];
            int v3 = nums[i];
            maxSum = max(v1, max(v2, v3));
            minSum = min(v1, min(v2, v3));
            res = max(res, max(abs(maxSum), abs(minSum)));
        }
        return res;
    }
};
