class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        int n=edges.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<n;i++){
            vector<int>e=edges[i];
            int src=e[0];
            int desti=e[1];
            adj[src].push_back(desti);
            adj[desti].push_back(src);
            
        }
        vector<bool>vis(V,false);
        vector<int>res(V,0);
        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src]=true;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int node=p.first;
            int desc=p.second;
            res[node]=desc;
            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i];
                if(vis[neighbour]==false){
                    q.push({neighbour,desc+1});
                    vis[neighbour]=true;
                }
            }
        }
        if(res[dest]==0){
            return -1;
        }
        return res[dest];
        
    }
};
