class MinStack {
    vector<int> vec;
    vector<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        if (min.empty() || min.back() >= val) min.push_back(val);
    }
    
    void pop() {
        int temp = vec.back();
        if (temp==min.back()) min.pop_back();
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return min.back();
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
