class Solution {
public:
    int countGoodSubstrings(string s) {
        int low = 0;
        int high = 2;
        int ans = 0;
        while (high < s.length()) {
            unordered_map<char, int> h;
            for (int i = low; i <= high; i++) {
                h[s[i]]++;
            }
            if (h.size() == 3) {
                ans++;
            }
            low = low + 1;
            high = high + 1;
        }
        return ans;
    }
};
