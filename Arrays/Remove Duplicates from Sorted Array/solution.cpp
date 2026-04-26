class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                k=k+1;
                nums[k]=nums[i];
              
                
            }
        }
       return k+1;
        
    }
};
