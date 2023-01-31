class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int K = strs[0].size();
        
        int answer = 0;
        for (int col = 0; col < K; col++) {
            for (int row = 1; row < strs.size(); row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    answer++;
                    break;
                }
            }
        }
        
        return answer;
    }
};