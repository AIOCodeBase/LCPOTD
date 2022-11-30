class Solution {
public:
    static constexpr int K = 1000;
    
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2 * K  + 1);
    
        for (int num : arr) {
            freq[num + K]++;
        }
        
        sort(freq.begin(), freq.end());
        
        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] && freq[i] == freq[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};