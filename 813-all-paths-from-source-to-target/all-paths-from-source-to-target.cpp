class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> res;
        vector<int> path{0};
        dfs(0,n-1,graph,res,path);
        return res;
    }
    void dfs(int node,int dest,vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>& path){
        if(node==dest){
            res.push_back(path);
        }
        for(int nei:graph[node]){
            path.push_back(nei);
            dfs(nei,dest,graph,res,path);
            path.pop_back();
        }
    }
};