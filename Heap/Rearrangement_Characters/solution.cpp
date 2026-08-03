class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first != a.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        string res = "";
        int seat = 0;
        unordered_map<char, int> f;
        for (int i = 0; i < s.length(); i++) {
            f[s[i]]++;
        }

        for (auto elem : f) {
            pq.push({elem.second, elem.first});
        }
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            int value = p.first;
            char character = p.second;
            if (res.size() == 0 || res[seat - 1] != character) {
                res = res + character;
                value--;
                if (value > 0) {
                    pq.push({value, character});
                }
            } else {

                if (pq.empty()) {
                    return "";
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                int v = p2.first;
                char charr = p2.second;
                res = res + charr;
                v--;
                if (v > 0) {
                    pq.push({v, charr});
                }
                pq.push({value, character});
            }
            seat++;
        }
        return res;
    }
};
