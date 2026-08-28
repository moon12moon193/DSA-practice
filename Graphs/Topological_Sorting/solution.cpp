class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegrees(V,0);
        for(int i=0;i<edges.size();i++){
            vector<int>p=edges[i];
            int src=p[0];
            int dest=p[1];
            adj[src].push_back(dest);
            indegrees[dest]++;
        }
        queue<int>q;
        vector<int>res;
        for(int i=0;i<indegrees.size();i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int value=q.front();
            q.pop();
            res.push_back(value);
            for(int i=0;i<adj[value].size();i++){
                int neighbour=adj[value][i];
                indegrees[neighbour]--;
                if(indegrees[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return res;
    }
};
