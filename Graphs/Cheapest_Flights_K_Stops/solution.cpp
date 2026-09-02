class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n,INT_MAX);
        vector<int>temp(n,INT_MAX);
        res[src]=0;
        temp[src]=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<flights.size();j++){
                int source=flights[j][0];
                int dest=flights[j][1];
                int weight=flights[j][2];
                if(res[source]!=INT_MAX && temp[dest]>res[source]+weight){
                    temp[dest]=res[source]+weight;
                }
            }
            res=temp;
        }
      
        if(res[dst]==INT_MAX){
            return -1;
        }else{
            return res[dst];
        }
        
        
    }
};
