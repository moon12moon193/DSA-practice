class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=INT_MIN;
        while(i<j){
            if(height[i]<height[j]){
                int ht=height[i];
                int width=j-i;
                int area=ht*width;
                maxi=max(maxi,area);
                i++;
            }else{
                int ht=height[j];
                int width=j-i;
                int area=ht*width;
                maxi=max(maxi,area);
                j--;
            }
        }
        return maxi;
        
    }
};
