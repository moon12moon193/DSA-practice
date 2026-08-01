class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        unordered_map<int, int> f;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int disc = x * x + y * y;
            f[i] = disc;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto elem : f) {
            int disc = elem.second;
            int element = elem.first;
            if (pq.size() < k) {
                pq.push({disc, element});
            } else {
                if (disc < pq.top().first) {
                    pq.pop();
                    pq.push({disc, element});
                } else {
                    continue;
                }
            }
        }
        while (!pq.empty()) {
            int index = pq.top().second;
            int first = points[index][0];
            int second = points[index][1];
            result.push_back({first, second});
            pq.pop();
        }
        return result;
    }
};
