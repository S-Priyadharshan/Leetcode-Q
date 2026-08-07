class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        for(int i=0;i<speed.size();i++){
            vec.emplace_back(position[i],speed[i]);
        }
        sort(vec.begin(),vec.end());
        stack<double>st;
        for(auto it:vec){
            double t=1.0*(target-it.first)/it.second;
            while(!st.empty()&&st.top()<=t){
                st.pop();
            }
            st.push(t);
        }
        return st.size();
    }
};