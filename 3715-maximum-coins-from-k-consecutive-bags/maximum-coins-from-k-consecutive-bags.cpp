class Solution {
public:
    using ll = long long;
    ll helper(vector<vector<int>>& coins,int k){
        sort(coins.begin(),coins.end());
        ll ans=0;
        int n=coins.size();
        int j=0;
        ll curr=0;
        for(int i=0;i<n;i++){

            ll end=(ll)coins[i][0]+k-1;
            ll pre=0;

            while(j<n && coins[j][1]<=end){
                curr+=(ll)(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }

            if(j<n && coins[j][0]<=end){
                pre=(end-coins[j][0]+1)*coins[j][2];
            }

            ans=max(ans,curr+pre);

            if(j==i)j++;
            else curr-=(ll)(coins[i][1]-coins[i][0]+1)*coins[i][2];
        }
        return ans;
    }
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        ll ans=helper(coins,k);

        for(auto& c:coins){
            ll l=c[0],r=c[1];
            c[0]=-r;
            c[1]=-l;
        }
        return max(ans,helper(coins,k));
    }
};