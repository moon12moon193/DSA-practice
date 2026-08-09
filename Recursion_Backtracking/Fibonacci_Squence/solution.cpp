class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        int firstLast=fib(n-1);
        int secondLast=fib(n-2);
        int ans=firstLast+secondLast;
        return ans;
        
    }
};
