class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> f;
        for (int i = 0; i < n; i++) {
            f[wordList[i]] = 1;
        }
        if(f.find(beginWord)==f.end()){
            f[beginWord]=1;
        }
        if(f.find(endWord)==f.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        f.erase(beginWord);
        while(!q.empty()){
            pair<string,int>p=q.front();
            q.pop();
            string word=p.first;
            int val=p.second;
            if(word==endWord){
                return val;
            }
            for(int i=0;i<word.size();i++){
                int character=word[i];
                for(int j=97;j<=122;j++){
                    if(j==character){
                        continue;
                    }
                    word[i]=j;
                    if(f.find(word)!=f.end()){
                        q.push({word,val+1});
                        f.erase(word);
                    }
                }
                word[i]=character;
            }
        }
        return 0;
    }
};
