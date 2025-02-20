class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxn=*max_element(candies.begin(),candies.end());
        for(int i:candies){
            if(i+extraCandies>=maxn)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};