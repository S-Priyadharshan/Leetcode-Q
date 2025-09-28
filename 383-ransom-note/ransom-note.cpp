class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>a(26,0);
        for(char ch:magazine)a[ch-'a']++;
        for(char ch:ransomNote){
            if(a[ch-'a']==0)return false;
            else a[ch-'a']--;
        }
        return true;
    }
};