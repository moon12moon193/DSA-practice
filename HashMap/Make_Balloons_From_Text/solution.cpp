class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> texi;
        string makeVal = "balloon";
        unordered_map<char, int> bllon;
        int res = INT_MAX;
        for (int i = 0; i < makeVal.length(); i++) {
            bllon[makeVal[i]]++;
        }
        for (int j = 0; j < text.length(); j++) {
            texi[text[j]]++;
        }
        for (auto k : bllon) {
            int tKey = k.first;
            int tVal = k.second;
            int bVal = texi[tKey];
            int ans = bVal / tVal;
            if (bVal >= tVal) {
                int ans = bVal / tVal;
                res = min(res, ans);
            } else {
                return 0;
            }
        }
        return res;
    }
};
