class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }

        int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto &d:dirs){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(res[nx][ny]>res[x][y]+1){
                        res[nx][ny]=res[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return res;
    }
};