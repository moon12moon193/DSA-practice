class Solution {
public:
void fun(int index,vector<int>&temp,vector<vector<int>>&result,vector<int>&candidates,int target,int sum){
    int n=candidates.size();
    if(index==n){
        if(sum==target){
            result.push_back({temp});
            return;
        }
        return;
    }
    fun(index+1,temp,result,candidates,target,sum);
    if(sum<=target){
        temp.push_back(candidates[index]);
        sum=sum+candidates[index];
        fun(index,temp,result,candidates,target,sum);
        temp.pop_back();
        sum=sum-candidates[index];
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        int index=0;
        int sum=0;
        fun(index,temp,result,candidates,target,sum);
        return result;
        
    }
};
