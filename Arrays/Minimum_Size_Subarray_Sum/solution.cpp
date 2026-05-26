class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        int len=0;
        while(j<nums.size()){
            sum=sum+nums[j];
            while(sum>=target){
                len=j-i+1;
                ans=min(len,ans);
                sum=sum-nums[i];
                i++;
                
            }
            j++;
        }
        if(ans==INT_MAX){
            return 0;
        }else{

        
        return ans;
        }
        
    }
};
