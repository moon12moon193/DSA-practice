class Solution {
public:
void fun(int open,int close,int n,string &temp,vector<string>&result){
    if(open==n && close==n){
        result.push_back({temp});
        return;
    }
    if(open<n){
        temp.push_back('(');
        fun(open+1,close,n,temp,result);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(')');
        fun(open,close+1,n,temp,result);
        temp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string>result;
        int open=0;
        int close=0;
        fun(open,close,n,temp,result);
        return result;

        
    }
};
