class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i==j || i<j){
            int temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        for(char i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        
    }
};
