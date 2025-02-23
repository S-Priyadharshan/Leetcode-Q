class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)return 1;
        if(s.size()==0)return 0;

        // int maxc=1;
        // int count=1;
        // string curr = "";
        // curr=s[0];
        // for(int i=1;i<s.size();i++){
        //     if(curr.find(s[i])==string::npos){
        //         curr+=s[i];
        //         count++;
        //     }else{
        //         curr=curr.substr(curr.find(s[i])+1);
        //         curr+=s[i];
        //         count=curr.size();
        //     }
        //     maxc=max(maxc,count);
        // }
        // return maxc;

        int maxs=0;
        unordered_map<char,int>mp;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]>=left){
                left=mp[s[i]]+1;
                mp[s[i]]=i;
            }else{
                mp[s[i]]=i;
                maxs=max(maxs,(i-left+1));
            }
        }
        return maxs;
    }
};