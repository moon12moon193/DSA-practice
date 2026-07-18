class Solution {
public:
    string removeDuplicates(string str) {
        string res="";
        stack<char>s;
        for(int i=0;i<str.length();i++){
            if(s.empty()){
                s.push(str[i]);
            }else{
                if(s.top()==str[i]){
                    s.pop();
                }else{
                    s.push(str[i]);
                }
            }
        }
        while(!s.empty()){
            char c=s.top();
            res=res+c;
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
