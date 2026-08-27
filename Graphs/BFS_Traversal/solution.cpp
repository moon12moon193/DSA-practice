class Solution {
  public:
  void fun(vector<vector<int>> &adj,int node,vector<bool>& vis,queue<int>& q,vector<int>& res){
      q.push(node);
      vis[node]=true;
      while(!q.empty()){
          int value=q.front();
          q.pop();
          res.push_back(value);
          for(int i=0;i<adj[value].size();i++){
              
              int neighbour=adj[value][i];
              if(vis[neighbour]==false){
              vis[neighbour]=true;
              q.push(neighbour);
              }
          }
      }
  }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int node=0;
        int n=adj.size();
        vector<int>res;
        queue<int>q;
        vector<bool>vis(n,false);
        fun(adj,node,vis,q,res);
        return res;
    }
};
