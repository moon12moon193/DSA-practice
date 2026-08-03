class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> f;
        unordered_map<char, int> free;
        int seat = 1;
        for (int i = 0; i < tasks.size(); i++) {
            f[tasks[i]]++;
            free[tasks[i]] = 1;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for (auto elem : f) {
            pq.push({elem.second, elem.first});
        }
        while (!pq.empty()) {
            vector<pair<int, char>> res;
            while (!pq.empty()) {
                pair<int, char> p1 = pq.top();
                pq.pop();
                int v1 = p1.first;
                char charr1 = p1.second;
                if (free[charr1] <= seat) {
                    free[charr1] = seat + n + 1;
                    v1--;
                    if (v1 > 0) {
                        pq.push({v1, charr1});
                    }
                    break;
                } else {
                    res.push_back({v1,charr1});
                }
            }
            seat++;
            if(res.size()>0){
                for(int i=0;i<res.size();i++){
                    pq.push({res[i].first,res[i].second});
                }
            }
        }
        return seat-1;
    }
};
