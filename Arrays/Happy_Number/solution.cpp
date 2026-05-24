class Solution {
public:
    int CalNum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            int ans = digit * digit;
            sum = sum + ans;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slowPointer = n;
        int fastPointer = n;
        do {
            slowPointer = CalNum(slowPointer);
            fastPointer = CalNum(CalNum(fastPointer));
        } while (slowPointer != fastPointer);
        if (fastPointer != 1) {
            return false;
        }
        return true;
       
    }
    
};
