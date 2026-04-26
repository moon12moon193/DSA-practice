class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int leftsum=nums[0];
        for(int i=1;i<n;i++){
            leftsum=leftsum+nums[i];
            nums[i]=leftsum;
        }
        return nums;
        
    }
};
