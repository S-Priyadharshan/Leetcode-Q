class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};    
        for(char ch:text){
            if(mp.find(ch)!=mp.end()){
                mp[ch]++;
            }
        }
        mp['l']/=2;
        mp['o']/=2;
        int ans=INT_MAX;
        for(auto i:mp){
            ans=min(ans,i.second);
        }
        return ans;
    }
};