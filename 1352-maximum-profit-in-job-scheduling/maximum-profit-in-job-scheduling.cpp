class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> vec;
        for(int i=0;i<startTime.size();i++){
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(vec.begin(),vec.end(),[&](const auto& a,const auto& b){
            return a[1]<b[1];
        });

        int n=vec.size();
        int maxend=vec[n-1][1];


        int j=0;
        int mx=0;

        sort(endTime.begin(),endTime.end());
        endTime.erase(unique(endTime.begin(),endTime.end()),endTime.end());

        vector<int>dp(endTime.size(),0);


        for(int t=0;t<dp.size();t++){
            while(j<n && vec[j][1]==endTime[t]){

                int idx = upper_bound(endTime.begin(),endTime.end(),vec[j][0])-endTime.begin()-1;

                int prev= (idx>=0) ? dp[idx]:0;

                mx=max(mx,vec[j][2]+prev);
                j++;
            }
            dp[t]=mx;
        }
        return mx;
    }
};