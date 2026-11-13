class Solution {
public:
    using pii =  pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto arr:times){
            int u=arr[0];
            int v=arr[1];
            int c=arr[2];
            adj[u].emplace_back(v,c);
        }

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();

            if(cost > dist[node])continue;

            for(auto [nei,wt]:adj[node]){
                if(cost + wt < dist[nei]){
                    dist[nei]=cost + wt;
                    pq.push({dist[nei],nei});
                }
            }
        }

        int ans=*max_element(dist.begin(),dist.end());

        if(ans==INT_MAX)return -1;
        return ans;

    }
};