class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        
    }
    
    void push(int x) {

        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.push(x);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        int ans = stack1.top();
        stack1.pop();
        return ans;
    }
    
    int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
    }
};