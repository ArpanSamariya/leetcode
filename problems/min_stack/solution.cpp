class MinStack {
public:
    stack<int> st;
    vector<int> vec;
     
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);  
        vec.push_back(val);
        if (vec.size() > 1) vec[vec.size() - 1] = min(vec[vec.size() - 1], vec[vec.size() - 2]);
    }
    
    void pop() {
        st.pop();
        vec.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return vec.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */