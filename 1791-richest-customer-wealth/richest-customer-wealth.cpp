class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto i:accounts){
            int sm=0;
            for(int j:i){
                sm+=j;
            }
            ans=max(ans,sm);
        }
        return ans;
    }
};