class MinStack {
public:
    stack<int> minstack;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        minstack.push(val);
        if(min.empty()){
            min.push(val);
        }
        else{
            if(val<=min.top()){
                min.push(val);
            }
        }
    }
    
    void pop() {
        int x = minstack.top();
        minstack.pop();
        if(x == min.top()){
            min.pop();
        }
    }
    
    int top() {
        return minstack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
