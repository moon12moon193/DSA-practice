class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() > 1) {

            sort(nums.begin(), nums.end());
        }
        int i=0;
        int count = 1;
         if (nums.size()== 1) {
                return nums[i];
            }

        for ( i = 1; i < nums.size() ; i++) {
           

                if (nums[i] == nums[i - 1]) {
                    count++;

                } else {
                    count = 1;
                }

                if (count > nums.size() / 2) {
                    return nums[i];
                }
            
        }

        return -1;
    }
};
