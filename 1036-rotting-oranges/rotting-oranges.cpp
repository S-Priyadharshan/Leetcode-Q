class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int day=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)count++;
            }
        }
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int s=q.size();
            bool rot=false;
            for(int i=0;i<s;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto j:dirs){
                    int nx=x+j[0];
                    int ny=y+j[1];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        count--;
                        rot=true;
                    }
                }
            }
            if(rot)day++;
        }
        return (count==0) ? day:-1;
    }
};