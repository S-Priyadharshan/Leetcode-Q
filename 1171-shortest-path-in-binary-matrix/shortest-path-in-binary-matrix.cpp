class Solution {
public:
    static constexpr int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static constexpr int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1)return -1;

        grid[0][0]=1;

        queue<pair<int,int>>q;
        q.emplace(0,0);

        while(!q.empty()){
            auto[r,c] = q.front();q.pop();

            int dist=grid[r][c];

            if(r==n-1 && c==m-1){
                return dist;
            }

            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {
                    
                    grid[nr][nc]=dist+1;
                    q.emplace(nr,nc);
                }

            }
        }
    return -1;
    }
};