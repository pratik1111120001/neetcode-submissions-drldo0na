class MinStack {
public:
    stack<long> s;
    long min;
    MinStack() {
        s = {};
        min=0;
    }
    
    void push(int val) {
        if(s.size() == 0){
            min = val;
            s.push(0);
        }
        else{
            s.push(val-min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        long curr = s.top();
        s.pop();
        if(curr < 0) min = min - curr;
    }
    
    int top() {
        long curr = s.top();
        return ((curr < 0) ? (int)min : (curr + min));
    }
    
    int getMin() {
        return (int)min;
    }
};
