class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete=arr[0];
        if(arr.size()==1){
            return noDelete;
        }
        int oneDelete=0;
        int res=INT_MIN;
        for(int i=1;i<arr.size();i++){
            int prevNodelete=noDelete;
            int prevOnedelete=oneDelete;
            noDelete=max(noDelete+arr[i],arr[i]);
            oneDelete=max(prevOnedelete+arr[i],prevNodelete);
            res=max(res,max(noDelete,oneDelete));

        }
        return res;
        
    }
};
