class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size()<t.size())return "";
        unordered_map<char,int>need,window;
        for(char ch:t)need[ch]++;
        int req=need.size();
        int formed=0;
        int left=0;
        int minlen=INT_MAX;
        int start=0;
        for(int i=0;i<s.size();i++){
            window[s[i]]++;
            if(need.count(s[i]) && window[s[i]]==need[s[i]]){
                formed++;
            }

            while(formed==req){
                if(i-left+1<minlen){
                    minlen=(i-left+1);
                    start=left;
                }
                window[s[left]]--;
                if(need.count(s[left]) && window[s[left]]<need[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        return minlen==INT_MAX ? "":s.substr(start,minlen);
    }
};