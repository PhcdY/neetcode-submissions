class MinStack {
    private:
    stack<int> Stack_Normal;
    stack<int> Stack_Min;
    
    public:
    MinStack() {
        // Có thể set stack rỗng, gì đó nma k cần
    }

    
    void push(int val) {
        Stack_Normal.push(val);
        if(Stack_Min.empty()||val<=Stack_Min.top()){
            Stack_Min.push(val);
        }

    }
    
    void pop() {
        if(Stack_Normal.top()==Stack_Min.top()){
            Stack_Min.pop();
        }
        Stack_Normal.pop();

    }
    
    int top() {
        return Stack_Normal.top();
    }
    
    int getMin() {
        return Stack_Min.top();
    }
};
