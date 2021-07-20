class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mins;
    MinStack() {    

    }
    
    void push(int x) {
        s.push(x);
        if (mins.empty()) {
            mins.push(x);
        }
        else {
            if (mins.top() <= x) {
                mins.push(mins.top());
            }
            else {
                mins.push(x);
            }
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
