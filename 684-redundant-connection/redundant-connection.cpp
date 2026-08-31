class Solution {
public:
    int find(int i,vector<int>& parent){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0);
        iota(parent.begin(),parent.end(),0);
        for(const auto& edge:edges){
            int rootu=find(edge[0],parent);
            int rootv=find(edge[1],parent);

            if(rootu==rootv)return edge;

            parent[rootu]=rootv;
        }
        return {};
    }
};