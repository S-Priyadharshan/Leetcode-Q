class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // vector<int>ans(k);
        // map<int,int>mp;
        // int n=nums.size();
        // for(int i:nums){
        //     mp[i]++;
        // }

        // vector<pair<int,int>> countn(mp.begin(),mp.end());

        // sort(countn.begin(),countn.end(),[](auto &a,auto &b){
        //     return a.second > b.second;
        // });

        // for(int i=0;i<k;i++){
        //         ans[i]=countn[i].first;
        // }

        // return ans;

        vector<int>ans(k);
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto&[i,f]:mp){
            pq.push({f,i});
            if(pq.size()>k){
                pq.pop();
            }
        }

        for(int i=k-1;i>=0;i--){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};