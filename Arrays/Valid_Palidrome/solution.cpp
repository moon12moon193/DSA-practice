class Solution {
public:
bool checkPalidrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
            
            

        }
        i++;
        j--;

    }
    return true;
}
    bool isPalindrome(string s) {
        int j=0;
        for(int i=0;i<s.size();i++){
            if((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z')){
                s[j]=tolower(s[i]);
                j++;
            }else if(s[i]<='9' && s[i]>='0'){
                s[j]=s[i];
                j++;
            }
        }
        s.resize(j);
        return checkPalidrome(s);
        
    }
};
