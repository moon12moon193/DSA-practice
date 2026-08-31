class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        vector<int>res(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<edges.size();i++){
            int source=edges[i][0];
            int dest=edges[i][1];
            int weight=edges[i][2];
            adj[source].push_back({dest,weight});
            adj[dest].push_back({source,weight});
        }
        res[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int disc=p.first;
            int node=p.second;
            if(disc>res[node]){
                continue;
            }
            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i].first;
                int wt=adj[node][i].second;
                if(disc+wt<res[neighbour]){
                    res[neighbour]=disc+wt;
                    pq.push({disc+wt,neighbour});
                }
                
            }
        }
        return res;
    }
};
