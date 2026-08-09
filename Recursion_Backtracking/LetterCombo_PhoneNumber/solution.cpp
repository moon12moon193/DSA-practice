class Solution {
public:
void fun(int index,string &digits,string &temp,vector<string>&result,unordered_map<char,string>&f){
    int n=digits.length();
    if(index==n){
        result.push_back({temp});
        return;
    }
    string t=f[digits[index]];
    for(int i=0;i<t.length();i++){
        temp.push_back(t[i]);
        fun(index+1,digits,temp,result,f);
        temp.pop_back();
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        int index=0;
        vector<string>result;
        string temp;
        fun(index,digits,temp,result,f);
        return result;
        
    }
};
