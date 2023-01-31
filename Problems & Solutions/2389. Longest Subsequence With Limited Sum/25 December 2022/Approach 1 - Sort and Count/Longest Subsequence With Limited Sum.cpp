class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for (auto query : queries) {
            int count = 0;
            for (auto num : nums) {
                if (query >= num) {
                    query -= num;
                    count++;
                }
                else {
                    break;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};