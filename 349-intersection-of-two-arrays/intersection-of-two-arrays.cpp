class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        vector<int>ans;
        for(int i:nums1)mp[i]++;
        for(int j:nums2){
            if(mp.find(j)!=mp.end() && mp[j]>0){
                mp[j]--;
                s.insert(j);
            }
        }
        for(int i:s)ans.push_back(i);
        return ans;
    }
};