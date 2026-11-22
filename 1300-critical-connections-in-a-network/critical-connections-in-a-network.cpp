class Solution {
public:
    vector<vector<int>> res;
    int time=0;
    void dfs(int u,int parent,vector<vector<int>>& adj,vector<int>& disc,vector<int>& low){
        disc[u]=low[u]=time++;

        for(int v:adj[u]){

            if(v==parent)continue;

            if(disc[v]==-1){
                dfs(v,u,adj,disc,low);

                low[u]=min(low[u],low[v]);

                if(low[v]>disc[u]){
                    res.push_back({u,v});
                }
            }else{
                low[u]=min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }        

        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<vector<int>> bridges;

        dfs(0,-1,adj,disc,low);
        return res;
    }
};