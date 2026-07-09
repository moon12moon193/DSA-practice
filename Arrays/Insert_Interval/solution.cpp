class Solution {
public:
vector<vector<int>> mergeInterval(vector<vector<int>>& ans1,vector<vector<int>>& ans2){
    int start1=ans1[0][0];
    int end1=ans1[0][1];
    for(int i=1;i<ans1.size();i++){
        int start2=ans1[i][0];
        int end2=ans1[i][1];
        if(start2<=end1){
            start1=start1;
            end1=max(end1,end2);
            continue;
        }
        ans2.push_back({start1,end1});
        start1=start2;
        end1=end2;
    }
    ans2.push_back({start1,end1});
    return ans2;

}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans1;
        bool insert=false;
        for(int i=0;i<intervals.size();i++){
            if(insert==false && newInterval[0]<intervals[i][0]){
                ans1.push_back({newInterval});
                insert=true;
            }
            ans1.push_back({intervals[i][0],intervals[i][1]});

        }
        if(insert==false){
            ans1.push_back({newInterval});
        }
        vector<vector<int>>ans2;
      vector<vector<int>>ans3=  mergeInterval(ans1,ans2);
      return ans3;
        
        
    }
};
