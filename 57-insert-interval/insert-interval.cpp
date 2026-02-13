class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int>i=newInterval;
        vector<vector<int>> res;
        for(auto v:intervals){
            if(max(v[0],i[0])<=min(v[1],i[1])){
                i[0]=min(v[0],i[0]);
                i[1]=max(v[1],i[1]);
            }else{
                res.push_back(v);
            }
        }
        bool cond=true;
        for(auto v:res){
            if(i[0]<v[0] && cond){
                ans.push_back(i);
                ans.push_back(v);
                cond=false;
            }else{
                ans.push_back(v);
            }
        }
        if(cond)ans.push_back(i);
        return ans;
    }
};