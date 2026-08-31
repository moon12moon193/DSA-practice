class Solution {
public:
bool isValid(int row,int col,int n,int m){
    if(row<0 || row>=n || col<0 || col>=m){
        return false;
    }
    return true;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            vector<int>t(m,INT_MAX);
            res[i]=t;
        }
       priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int disc=p.first;
            int row=p.second.first;
            int col=p.second.second;
            if(disc>res[row][col]){
                continue;
            }
            for(int i=0;i<4;i++){
                int r=row+x[i];
                int c=col+y[i];
                if(!isValid(r,c,n,m)){
                    continue;
                }
                int absDiff=abs(heights[row][col]-heights[r][c]);
                int newWeight=max(absDiff,disc);
                if(newWeight<res[r][c]){
                    res[r][c]=newWeight;
                    pq.push({newWeight,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
        
    }
};
