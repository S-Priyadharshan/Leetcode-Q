class Solution {
public:
    int minLength(string s){
        stack<char>st;
        for(char ch:s){
            if(ch=='B'&&!st.empty()){
                if(st.top()=='A')st.pop();
                else st.push(ch);
            }else if(ch=='D'&&!st.empty()){
                if(st.top()=='C')st.pop();
                else st.push(ch);
            }else{
                st.push(ch);
            }
        }
        return st.size();
    }
};