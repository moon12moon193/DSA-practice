class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> f;
        for (int i = 0; i < s.length(); i++) {
            f[s[i]]++;
        }
        for (auto k : f) {
            int key=k.first;
            int val = k.second;
            if (val % 2 == 0) {
                ans = ans + val;
                f[key]=0;
            } else {
                val = val - 1;
                ans = ans + val;
                f[key]=1;
               
            }
        }
        for(auto l:f){
            int key=l.first;
            int val=l.second;
            if(f[key]==1){
                return ans+1;
            }
        }
        

        return ans;
    }
};
