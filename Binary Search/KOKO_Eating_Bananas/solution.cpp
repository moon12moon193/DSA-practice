class Solution {
public:
    long long int TotalTime(vector<int>& piles, int mid) {
        long long int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            int ans = piles[i] / mid;
            hours = hours + ans;
            if (piles[i] % mid != 0) {
                hours = hours + 1;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int maxi = INT_MIN;
        int res = -1;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        int high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int hours = TotalTime(piles, mid);
            if (hours > h) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};
