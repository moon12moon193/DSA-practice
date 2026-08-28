class Solution {
public:
    void dfs(vector<vector<int>>& graph, int colour, vector<int>& colours,
             int node, bool& res) {
        colours[node] = colour;
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (colours[neighbour] != -1 && colours[neighbour] == colour) {
                res = false;
            }
            if (colours[neighbour] == -1) {
                dfs(graph, 1-colour, colours, neighbour, res);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool res = true;
        vector<int> colours(n, -1);
        int colour = 0;
        for (int i = 0; i < n; i++) {
            if (colours[i] == -1) {
                dfs(graph, colour, colours, i, res);
            }
        }
        return res;
    }
};
