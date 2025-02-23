class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // if(points.size()<3)return 0;
        int res=0;
        unordered_map<int,int>mp;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                int dist = pow((points[j][0]-points[i][0]),2)+pow((points[j][1]-points[i][1]),2);
                res += 2*mp[dist]++;                
            }
            mp.clear();
        }
        return res;
    }
};