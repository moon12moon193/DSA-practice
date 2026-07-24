class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        if(nums[n-1]>nums[0]){
            return nums[0];
        }else{
            int low=0;
            int high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]>nums[n-1]){
                    low=mid+1;
                }else{
                     res=nums[mid];
                    high=mid-1;
                }
            }
            return res;
            
        }
        
        
    }
};
