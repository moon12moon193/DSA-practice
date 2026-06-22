class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
          return 0;  
        }else{

        
        int low=0;
        int high=0;
        int maxi=INT_MIN;
        int k=0;
         unordered_map<char,int>h;
        while(high<s.length()){
            h[s[high]]++;
            k=high-low+1;
            while(h.size()<k){
                h[s[low]]--;
                if(h[s[low]]==0){
                    h.erase(s[low]);
                }
                low=low+1;
                k=high-low+1;


            }
            if(h.size()==k){
                maxi=max(maxi,k);
            }
            high=high+1;


        }
        return maxi;
        }
        
    }
};
