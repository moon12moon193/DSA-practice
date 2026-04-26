class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> Leftarray(n, 0);
        vector<int> Rightarray(n, 0);
        int leftsum = 0;
        int rightsum=0;
    for(int i=0;i<nums.size();i++){
        if(i==0){
            Leftarray[i]=leftsum;
        }else{
            leftsum=leftsum+nums[i-1];
            Leftarray[i]=leftsum;
        }
    }
    for(int j=n-1;j>=0;j--){
        if(j==n-1){
            Rightarray[j]=rightsum;
        }else{
            rightsum=rightsum+nums[j+1];
            Rightarray[j]=rightsum;
        }
    }
        for (int k = 0; k< nums.size(); k++) {
            if (Leftarray[k] == Rightarray[k]) {
                return k;
            }
        }
        return -1;
    }
};
