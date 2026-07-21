class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ransom;
        unordered_map<char,int>magzine;
        for(int i=0;i<ransomNote.length();i++){
            ransom[ransomNote[i]]++;
        }
        for(int j=0;j<magazine.length();j++){
            magzine[magazine[j]]++;
        }
        for(auto k:ransom){
            int ransomKey=k.first;
            int ransomVal=k.second;
            int magzineVal=magzine[ransomKey];
            if(magzineVal<ransomVal){
                return false;
            }
        }
        return true;
        
    }
};
