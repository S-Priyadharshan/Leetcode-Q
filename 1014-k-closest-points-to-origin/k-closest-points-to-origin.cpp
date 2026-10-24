class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [](const auto& a,const auto& b){
            return a.first < b.first;
        };

        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,decltype(cmp)>pq(cmp);

        for(auto i:points){
            double dist=sqrt(((0-i[0])*(0-i[0]))+((0-i[1])*(0-i[1])));
            pq.push({dist,{i[0],i[1]}});
            if(pq.size()>k){
                while(pq.size()>k)pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            auto res=pq.top();
            pq.pop();
            vector<int>temp={res.second.first,res.second.second};
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};