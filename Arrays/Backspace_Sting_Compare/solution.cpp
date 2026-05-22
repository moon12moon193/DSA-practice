class Solution {
public:
string removeCharacters(string str){
    int j=0;

    for(int i=0;i<str.length();i++){
        if(i==0 && str[i]=='#'){
            continue;
        }
        if(str[i]>='a' && str[i]<='z'){
            str[j]=str[i];
            j++;
        }else{
            if(j>0){
                j=j-1;
            }
        }
    }
    str.resize(j);
    return str;
}


bool EqualStrs(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }else{
        int i=str1.length()-1;
        int j=str2.length()-1;
        while(i>=0 && j>=0){
            if(str1[i]!=str2[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
}
    bool backspaceCompare(string s, string t) {
        string str1=removeCharacters(s);
        string str2=removeCharacters(t);
        bool ans=EqualStrs(str1,str2);
        return ans;
        
    }
};
