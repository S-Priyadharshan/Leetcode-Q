class Solution {
public:
using ll=long long;
using pll= pair<ll,ll>;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        for(int i=0;i<k;i++){
            available.insert(i);
        }

        priority_queue<pll,vector<pll>,greater<pll>>busy;
        vector<int> cnt(k,0);


        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];

            while(!busy.empty() && busy.top().first<=time){
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            if(available.empty())continue;

            int req=i%k;

            auto idx = available.lower_bound(req);

            if(idx==available.end()){
                idx=available.begin();
            }

            int server = *idx;
            cnt[server]++;
            available.erase(server);

            busy.push({(ll) time + load[i],server});
        }

        int mx=*max_element(cnt.begin(),cnt.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(cnt[i]==mx){
                ans.push_back(i);
            }
        }

        return ans;
    }
};