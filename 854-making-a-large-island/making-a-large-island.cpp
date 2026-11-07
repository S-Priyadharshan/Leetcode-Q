class Solution {
public:
    int dirs[5] = {0,1,0,-1,0};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int id=2;
        map<int,int>mp;
        mp[0]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count = dfs(grid,vis,i,j,id,0);
                    ans=max(ans,count);
                    mp[id]=count;
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int cnt=0;
                    unordered_set<int>s;
                    if(i-1>=0)s.insert(grid[i-1][j]);
                    if(j-1>=0)s.insert(grid[i][j-1]);
                    if(i+1<n)s.insert(grid[i+1][j]);
                    if(j+1<m)s.insert(grid[i][j+1]);
                    for(const int& x:s)cnt+=mp[x];
                    ans=max(ans,cnt+1);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int x,int y,int id,int count){
        vis[x][y]=1;
        grid[x][y]=id;
        count++;
        for(int i=0;i<4;i++){
            int nx=x+dirs[i];
            int ny=y+dirs[i+1];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1 && !vis[nx][ny]){
                count = dfs(grid,vis,nx,ny,id,count);
            }
        }
        return count;
    }
};