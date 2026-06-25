class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int result = INT_MIN;
        int len = 0;
        int arr[2] = {0};
        int zeroNum = 0;
        while (high < nums.size()) {
            arr[nums[high] - 0]++;
            len = high - low + 1;
            zeroNum = len - arr[1];
            while (zeroNum > k) {
                arr[nums[low] - 0]--;
                low++;
                len=high-low+1;
                zeroNum=len-arr[1];
            }

            result = max(result, len);
            high = high + 1;
        }
        return result;
    }
};
