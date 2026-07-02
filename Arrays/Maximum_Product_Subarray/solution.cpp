class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct=nums[0];
        int maxProduct=nums[0];
        int GlobalProduct=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=minProduct*nums[i];
            int v3=maxProduct*nums[i];
            minProduct=min(v1,min(v2,v3));
            maxProduct=max(v1,max(v2,v3));
            GlobalProduct=max(GlobalProduct,maxProduct);
        }
        return GlobalProduct;
        
    }
};
