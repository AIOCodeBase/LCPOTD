class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto it : tokens){
            if(it == "+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                x += y;
                s.push(x);
            }
            else if(it == "-"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                y -= x;
                s.push(y);
            }
            else if(it == "*"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                x *= (1ll*y);
                s.push(x);
            }
            else if(it == "/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                y /= x;
                s.push(y);
            }
            else{
                bool sign = false;
                int x = 0;
                for(auto i : it){
                    if(i == '-'){
                        sign = true;
                        continue;
                    }
                    int y = int(i) - 48;
                    x = 10*x + y;
                }
                if(sign) x *= -1;
                s.push(x);
            }
        }
        return s.top();
    }
};