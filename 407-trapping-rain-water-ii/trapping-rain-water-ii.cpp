class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        using Cell = tuple<int, int, int>;
        priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                    minHeap.emplace(heightMap[r][c], r, c);
                    visited[r][c] = true;
                }
            }
        }

        int total=0;
        vector<int> dirs={0,1,0,-1,0};

        while(!minHeap.empty()){
            auto[h,r,c] = minHeap.top();
            minHeap.pop();

            for(int i=0;i<4;i++){
                int nr=r+dirs[i];
                int nc=c+dirs[i+1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc]=true;

                    if(heightMap[nr][nc]<h){
                        total+=h-heightMap[nr][nc];
                    }

                    minHeap.emplace(max(h,heightMap[nr][nc]),nr,nc);
                }
            
            }
        }

        return total;
    }
};