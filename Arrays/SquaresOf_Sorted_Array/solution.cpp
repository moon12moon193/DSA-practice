class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        while(i<nums.size() && nums[i]<0){
            i++;
        }
        int j=i-1;
        for(int k=0;k<nums.size();k++){
            nums[k]=nums[k]*nums[k];
        }
        if(i==0){
            return nums;
        }else if(i==nums.size()){
            reverse(nums.begin(),nums.end());
            return nums;
        }else{
            vector<int>result(nums.size(),0);
            int l=0;
            while(i<nums.size() && j>=0){
                if(nums[i]<nums[j]){
                    result[l]=nums[i];
                    i++;
                    l++;
                }else{
                    result[l]=nums[j];
                    j--;
                    l++;
                }
            }
            while(i<nums.size()){
                result[l]=nums[i];
                i++;
                l++;
            }
            while(j>=0){
                result[l]=nums[j];
                j--;
                l++;
            }
            return result;
        }
        
    }
};
