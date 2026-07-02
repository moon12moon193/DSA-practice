class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=nums[0];
        int GlobalMax=nums[0];
        if(nums.size()==1){
            return GlobalMax;
        }
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=currMax+nums[i];
            currMax=max(v1,v2);
            GlobalMax=max(GlobalMax,currMax);
        }
        return GlobalMax;
        
    }
};
