class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)return 1;
        if(s.size()==0)return 0;

        int maxc=1;
        int count=1;
        string curr = "";
        curr=s[0];
        for(int i=1;i<s.size();i++){
            if(curr.find(s[i])==string::npos){
                curr+=s[i];
                count++;
            }else{
                curr=curr.substr(curr.find(s[i])+1);
                curr+=s[i];
                count=curr.size();
            }
            maxc=max(maxc,count);
        }
        return maxc;
    }
};