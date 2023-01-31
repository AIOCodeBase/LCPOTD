class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sequence;
        function<void(int)> backtrack;
        backtrack = [&nums, &sequence, &result, &backtrack](int index) -> void {
            if (index == nums.size()) {
                if (sequence.size() >= 2) {
                    result.insert(sequence);
                }
                return;
            }
            if (sequence.empty() || sequence.back() <= nums[index]) {
                sequence.push_back(nums[index]);
                // call recursively
                backtrack(index + 1);
                sequence.pop_back();
            }
            backtrack(index + 1);
        };
        backtrack(0);
        return vector(result.begin(), result.end());
    }
};