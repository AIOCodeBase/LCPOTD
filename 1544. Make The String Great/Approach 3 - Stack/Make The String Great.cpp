class Solution {
public:
    string makeGood(string s) {
        // Use stack to store the visited characters.
        vector<char> stack;
        
        // Iterate over 's'.
        for (auto currChar : s) {
            // If the current character make a pair with the last character in the stack,
            // remove both of them. Otherwise, we add the current character to stack.
            if (!stack.empty() && abs(stack.back() - currChar) == 32)
                stack.pop_back(); 
            else
                stack.push_back(currChar);
        }
        
        // Returns the string concatenated by all characters left in the stack.
        string ans(stack.begin(), stack.end());
        return ans;
    }
};