class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1);
        vector<int> finish(n+1);

        for(auto& arr:relations){
            adj[arr[0]].push_back(arr[1]);
            indegree[arr[1]]++;
        }

        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                finish[i]=time[i-1];
            }
        }
        int mxt=-1;
        while(!q.empty()){
            int node=q.front();q.pop();
            if(finish[node]>mxt){
                mxt=finish[node];
            }
            for(int nei:adj[node]){
                indegree[nei]--;
                finish[nei]=max(finish[nei],time[nei-1]+finish[node]);
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        // for(int i:finish)cout<<i<<"\n";
        return mxt;      
    }
};