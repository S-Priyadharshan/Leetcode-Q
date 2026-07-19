class Solution {
public:
    vector<int>dirs = {0,1,0,-1,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 
        int n=heights.size(),m=heights[0].size();       
        vector<vector<int>> ans;
        vector<vector<bool>> pvis(n,vector<bool>(m)),avis(n,vector<bool>(m));
        for(int i=0;i<m;i++){
            if(!pvis[0][i]){
                dfs(0,i,pvis,heights);
            }
            if(!avis[n-1][i]){
                dfs(n-1,i,avis,heights);
            }
        }
        for(int i=0;i<n;i++){
            if(!pvis[i][0]){
                dfs(i,0,pvis,heights);
            }
            if(!avis[i][m-1]){
                dfs(i,m-1,avis,heights);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pvis[i][j] && avis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(int x,int y,vector<vector<bool>>& vis,vector<vector<int>>& heights){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx = x+dirs[i];
            int ny = y+dirs[i+1];
            if(nx>=0 && ny>=0 && nx<heights.size() && ny<heights[0].size()
            && heights[nx][ny]>=heights[x][y] && !vis[nx][ny]){
                dfs(nx,ny,vis,heights);
            }
        }
    }
};