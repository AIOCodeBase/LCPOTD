class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        
        vector<long long> prefixSum(n + 1);
        vector<long long> suffixSum(n + 1);
        
        for (int index = 0; index < n; ++index) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }
        
        for (int index = n - 1; index >= 0; --index) {
            suffixSum[index] = suffixSum[index + 1] + nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            long long leftPartAverage = prefixSum[index + 1];
            leftPartAverage /= (index + 1);
            
            long long rightPartAverage = suffixSum[index + 1];
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