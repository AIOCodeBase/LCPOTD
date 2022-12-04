class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        
        for (int index = 0; index < n; ++index) {
            long long leftPartAverage = 0;
            for (int i = 0; i <= index; ++i) {
                leftPartAverage += nums[i];
            }
            leftPartAverage /= (index + 1);
            
            long long rightPartAverage = 0;
            for (int j = index + 1; j < n; ++j) {
                rightPartAverage += nums[j];
            }
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = int(abs(leftPartAverage - rightPartAverage));
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }
        
        return ans;
    }
};