class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int sz=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<trips.size();i++){
            while(!pq.empty() && trips[i][1]>=pq.top().first){
                sz-=pq.top().second;
                pq.pop();
            }
            sz+=trips[i][0];
            if(sz>capacity)return false;
            pq.emplace(trips[i][2],trips[i][0]);
        }
        return true;
    }
};