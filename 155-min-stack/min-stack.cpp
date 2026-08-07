class MinStack {
private:

    vector<pair<int,int>> st;

public:
    MinStack() {
        
    }
    
    void push(int value) {
        int mn=getMin();
        if(st.empty() || value<mn){
            mn=value;
        }    
        st.emplace_back(value,mn);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.empty() ? -1:st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */