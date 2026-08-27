class Solution {
	public:
	void fun(vector<vector<int>> & adj, vector<int>& res, int node, vector<bool>& vis) {
		res.push_back(node);
		vis[node] = true;
		for (int i = 0; i<adj[node].size(); i++) {
			int neighbour = adj[node][i];
			if (vis[neighbour] == false) {
				vis[neighbour] = true;
				fun(adj, res, neighbour, vis);
			}
			
		}
		return;
	}
	vector<int> dfs(vector<vector<int>> & adj) {
		// Code here
		vector<int>res;
		int n=adj.size();
		int node = 0;
		vector<bool>vis(n,false);
		fun(adj, res, node, vis);
		return res;
	}
};
