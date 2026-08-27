class Solution {
public:
bool isValid(int row,int col,int n,int m){
    if(row<0 || row>=n || col<0 || col>=m){
        return false;
    }
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        int time=0;
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
                if(grid[i][j]==1){
                    fresh++;
                }

            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int size=q.size();
            while(size>0){
                pair<int,int>value=q.front();
                q.pop();
                size--;
                int i=value.first;
                int j=value.second;
                for(int k=0;k<4;k++){
                    int row=i+x[k];
                    int col=j+y[k];
                    if(isValid(row,col,n,m)==true && grid[row][col]==1 ){
                        q.push({row,col});
                        grid[row][col]=-1;
                        fresh--;
                    }
                }

            }
        }
        if(fresh>0){
            return -1;
        }
        return time;
        
        
    }
};
