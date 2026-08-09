class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,prices[i]);
            ans=max(mx-prices[i],ans);
        }
        return ans;
    }
};