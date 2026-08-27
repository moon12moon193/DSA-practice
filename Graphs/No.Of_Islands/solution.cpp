class Solution {
public:
bool isValid(int row,int col,int n,int m){
    if(row<0 || row>=n || col<0 || col>=m){
        return false;
    }
    return true;
}
void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid,int n,int m,int x[4],int y[4]){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];
        if(isValid(row,col,n,m)==true && grid[row][col]=='1' && vis[row][col]==0){
            dfs(row,col,vis,grid,n,m,x,y);
        }
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int n = grid.size();
        int m = grid[0].size();
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, vis, grid,n,m,x,y);
                    res++;
                }
            }
        }
        return res;
    }
};
