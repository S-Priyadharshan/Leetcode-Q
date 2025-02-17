class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string ans;
        for(char &ch:s){
            if(!st.empty()&&abs(st.top()-ch)==32){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};