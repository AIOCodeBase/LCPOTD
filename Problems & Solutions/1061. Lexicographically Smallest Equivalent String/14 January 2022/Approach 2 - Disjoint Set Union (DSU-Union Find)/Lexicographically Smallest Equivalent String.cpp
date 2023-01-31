class Solution {
public:
    array<int, 26> representative;
    
    int find(int x) {
        if (representative[x] == x) {
            return x;
        }
        
        return representative[x] = find(representative[x]);
    }
    
    void performUnion(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        if (x < y) {
            representative[y] = x;
        } else {
            representative[x] = y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) {
            representative[i] = i;
        }
        
        for (int i = 0; i < s1.size(); i++) {
            performUnion(s1[i] - 'a', s2[i] - 'a');
        }
        
        string ans;
        for (char c : baseStr) {
            ans += (char)(find(c - 'a') + 'a');
        }
        
        return ans;
    }
};