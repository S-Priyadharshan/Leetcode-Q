class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(const auto&s:strs){
            vector<int>freq(26,0);
            for(const char&ch:s){
                freq[ch-'a']++;
            }
            string hash="#";
            for(int i:freq){
                hash+=to_string(i);
                hash+="#";
            }
            mp[hash].push_back(s);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};