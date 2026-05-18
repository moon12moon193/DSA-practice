class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(m+n,0);
        int k=0;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                temp[k]=nums1[i];
                k++;
                i++;
            }else{
                temp[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<m){
             temp[k]=nums1[i];
                k++;
                i++;

        }
        while(j<n){
             temp[k]=nums2[j];
                k++;
                j++;

        }
        for(int l=0;l<m+n;l++){
            nums1[l]=temp[l];

        }
        
    }
};
