class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int>pse(n),nse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            pse[i]= st.empty() ? -1:st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            int width = nse[i]-pse[i]-1;
            int area=height[i]*width;
            mx=max(mx,area);
        }
        return mx;
    }
};