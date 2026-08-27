class Solution {
	public:
	void dfs(vector<vector<int>>& adj, int node, int parent, vector<bool>& vis, bool& cycle) {
		vis[node] = true;
		for (int i = 0; i<adj[node].size(); i++) {
			int neighbour = adj[node][i];
			if (vis[neighbour] == true && neighbour != parent) {
				cycle = true;
			}
			if (vis[neighbour] == false) {
			    
				dfs(adj, neighbour, node, vis, cycle);
			}
		}
		return;
	}
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		bool cycle = false;
		
		vector<vector<int>> adj(V);
		for (int i = 0; i<edges.size(); i++) {
			vector<int>e = edges[i];
			int src = e[0];
			int dest = e[1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
		vector<bool>vis(V, false);
		for (int i = 0; i<V; i++) {
			if (vis[i] == 0) {
				dfs(adj, i, -1, vis, cycle);
			}
		}
		return cycle;
	}
};
