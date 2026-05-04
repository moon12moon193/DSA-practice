class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        while(j<n){
            nums.push_back(nums[j]);
            j++;
        }
        return nums;
        
    }
};
