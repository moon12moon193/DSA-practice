class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ones=0;
        int zeros=0;
        int res=INT_MIN;
        bool ans=false;
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros=zeros+1;
            }else{
                ones=ones+1;
            }
            int diff=zeros-ones;
            if(diff==0){
                ans=true;
                res=max(res,i+1);
                continue;
            }
            if(f.find(diff)==f.end()){
                f[diff]=i;
            }else{
                ans=true;
                int len=i-f[diff];
                res=max(res,len);
            }
        }
        if(ans==true){
            return res;
        }else{
            return 0;
        }
        
    }
};
