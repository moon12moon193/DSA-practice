class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size(),0);
        int i=0;
        int j=n;
        while(i<n && j<nums.size()){
            result[i+i]=nums[i];
            result[2*i+1]=nums[j];
            i++;
            j++;
        }
        return result;
        
    }
};
