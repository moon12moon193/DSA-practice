class Solution {
public:
    int FindMaxFreq(int arr[]) {
        int maxi = INT_MIN;
        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int low = 0;
        int high = 0;
        int result = INT_MIN;
        int arr[26] = {0};
        int len = 0;
        int maxFreq = 0;
        int diff = 0;
        while(high<s.length()){
            arr[tolower(s[high]) - 'a']++;
            len = high - low + 1;
            maxFreq = FindMaxFreq(arr);
            diff = len - maxFreq;
            while (diff > k) {
                arr[tolower(s[low]) - 'a']--;
                low++;
                len = high - low + 1;
                maxFreq = FindMaxFreq(arr);
                diff = len - maxFreq;
            }
            result = max(result, len);
            high = high + 1;

            
            
        }
        return result;
    }
};
