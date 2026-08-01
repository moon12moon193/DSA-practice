class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> result;
        unordered_map<int, int> f;
        for (int i = 0; i < nums.size(); i++) {
            f[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (auto elem : f) {
            int freq = elem.second;
            int element = elem.first;
            if (pq.size() < k) {
                pq.push({freq, element});
            } else {
                if (freq > pq.top().first) {
                    pq.pop();
                    pq.push({freq, element});
                } else {
                    continue;
                }
            }
        }
        while (!pq.empty()) {
            int ans = pq.top().second;
            result.push_back(ans);
            pq.pop();
        }
        return result;
    }
};
