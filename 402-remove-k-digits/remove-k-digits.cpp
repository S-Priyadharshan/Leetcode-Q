class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k)return "0";
        stack<int>st;
        for(char ch:num){
            while(!st.empty()&&st.top()>(ch-'0')&&k>0){
                st.pop();
                k--;
            }
            st.push(ch-'0');
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string res;
        for(int i:ans)res+=to_string(i);
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);
        return res.empty() ? "0":res;
    }
};