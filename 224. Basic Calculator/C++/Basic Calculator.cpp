class Solution {
public:
    stack<char> all_ops;
    stack<long long> all_nums;
    unordered_map<char, int> priority;

    void do_math() {
        int oprnd1 = all_nums.top(); all_nums.pop();
        int oprnd2 = all_nums.top(); all_nums.pop();
        char op = all_ops.top(); all_ops.pop();
        int rslt = 0;
        if (op == '+') rslt = oprnd1 + oprnd2;   
        else if (op == '-') rslt = oprnd2 - oprnd1;
        all_nums.push(rslt);
    }

    void replace(string &s, string a, string b) {
        int pos = s.find(a), m = a.size();
        while (pos != -1) {
            s.replace(pos, m, b);
            pos = s.find(a);
        }
    }

    int calculate(string s) {
        replace(s, " ", "");
        replace(s, "(-", "(0-"); 
        all_nums.push(0);
        priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        for (int i = 0; i != s.size(); ++i) {
            auto c = s[i];
            if (isdigit(c)) {
                long long current_num = 0, j = i;
                while (j < s.size() && isdigit(s[j])) {
                    current_num = current_num * 10 + (s[j] - '0');
                    ++j;
                }
                all_nums.push(current_num);
                i = j - 1;
            }
            else if (c == '(')
                all_ops.push(c);
            else if (c == ')') {
                while (all_ops.top() != '(')
                    do_math();
                all_ops.pop();
            }
            else {
                while (!all_ops.empty() && all_ops.top() != '(')
                    do_math();
                all_ops.push(c);
            }
        }
        while (!all_ops.empty())
            do_math();
        return all_nums.top();
    }
};