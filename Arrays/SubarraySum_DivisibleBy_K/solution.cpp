class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            count=count+f[rem];
            f[rem]++;
        }
        return count;
        
    }
};
