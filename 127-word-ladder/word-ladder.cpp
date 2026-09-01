class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.emplace(beginWord,1);

        while(!q.empty()){
            auto[str,count]=q.front();
            q.pop();

            if(str==endWord)return count;

            for(int i=0;i<str.size();i++){
                char org=str[i];

                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;

                    if(st.find(str)!=st.end()){
                        st.erase(str);
                        q.emplace(str,count+1);
                    }
                }
                str[i]=org;
            }
        }
        return 0;
    }
};