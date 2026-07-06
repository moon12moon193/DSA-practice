class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> f;
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            int ques = sum - k;

            ans = ans + f[ques];

            f[sum]++;
        }
        return ans;
    }
};
