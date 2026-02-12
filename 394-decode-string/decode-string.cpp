class Solution {
public:
    string decodeString(string s) {
       string ans="";
       stack<char>st;

       for(char ch:s){
        if(ch==']'){
            string temp="";
            while(!st.empty() && st.top()!='['){
                temp=st.top()+temp;
                st.pop();
            }
            st.pop();
            int sz=0,base=1;
            while(!st.empty() && isdigit(st.top())){
                sz+=(st.top()-'0')*base;
                base*=10;
                st.pop();
            }
            string res="";
            while(sz--)res+=temp;
            for(char ch:res)st.push(ch);
        }else{
            st.push(ch);
        }
       }
       while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
       } 
       return ans;
    }
};