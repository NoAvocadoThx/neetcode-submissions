class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        int mins = s.empty() ? val : min(val, s.top().second);
        s.push({val, mins});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
