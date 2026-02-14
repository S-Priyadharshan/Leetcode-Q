class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long>st;
        for(long long i:nums){
            while(!st.empty()  && st.top()==i){
                i+=st.top();
                st.pop();
            }
            st.push(i);
        }
        vector<long long>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};