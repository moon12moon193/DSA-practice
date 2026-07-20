class Solution {
public:
    string removeDuplicates(string st, int k) {
        stack<pair<char, int>> s;
        string res = "";
        for (int i = 0; i < st.length(); i++) {
            if (s.empty()) {
                s.push({st[i], 1});

            } else {
                if (st[i] != s.top().first) {
                    s.push({st[i], 1});
                } else {
                    if (s.top().second == k - 1) {
                        s.pop();
                    } else {
                        s.top().second = s.top().second + 1;
                    }
                }
            }
        }

        while (!s.empty()) {

            while (s.top().second > 0) {
                res += s.top().first;
                s.top().second = s.top().second - 1;
            }
            s.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
