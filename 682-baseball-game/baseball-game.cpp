class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string s:operations){
            if(s=="+"){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.push(op2);
                st.push(op1+op2);
            }else if(s=="D"){
                int prev=st.top();
                st.push(2*prev);
            }else if(s=="C"){
                st.pop();
            }else{
                st.push(stoi(s));
            }
        }
        int sumn=0;
        while(!st.empty()){
            sumn+=st.top();
            st.pop();
        }
        return sumn;
    }
};