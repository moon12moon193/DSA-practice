class Solution {
public:
    bool BothEqual(int string1[], int string2[]) {
        for (int l = 0; l < 26; l++) {
            if (string1[l] != string2[l]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }

        int string2[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            string2[s1[i] - 'a']++;
        }
        int string1[26] = {0};
        int low = 0;
        int high = s1.length();
        for (int j = low; j < high; j++) {
            string1[s2[j] - 'a']++;
        }
        if (BothEqual(string1, string2)) {
            return true;
        }
        for (int k = high; k < s2.length(); k++) {

            string1[s2[low] - 'a']--;
            low++;
            string1[s2[k] - 'a']++;
            if (BothEqual(string1, string2)) {
                return true;
            }
        }
        return false;
    }
};
