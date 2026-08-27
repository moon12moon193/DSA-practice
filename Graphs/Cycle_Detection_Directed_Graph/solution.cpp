class Solution {
  public:
  void dfs( vector<vector<int>>& adj,int node,vector<bool>& vis,vector<bool>& path,bool& cycle){
      vis[node]=true;
      path[node]=true;
      for(int i=0;i<adj[node].size();i++){
          int neighbour=adj[node][i];
          if(vis[neighbour]==true && path[neighbour]==true){
              cycle=true;
          }
          if(vis[neighbour]==false){
              dfs(adj,neighbour,vis,path,cycle);
          }
      }
      path[node]=false;
      return;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        bool cycle=false;
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            vector<int>p=edges[i];
            int src=p[0];
            int dest=p[1];
            adj[src].push_back(dest);
            
        }
        vector<bool>vis(V,false);
        vector<bool>path(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(adj,i,vis,path,cycle);
            }
        }
        return cycle;
    }
};
