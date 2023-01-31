class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        min_avg_diff = math.inf
        
        prefix_sum = [0] * (n + 1)
        suffix_sum = [0] * (n + 1)
        
        for index in range(n):
            prefix_sum[index + 1] = prefix_sum[index] + nums[index];
        
        for index in range(n - 1, -1, -1):
            suffix_sum[index] = suffix_sum[index + 1] + nums[index];
        
        for index in range(n):
            left_part_average = prefix_sum[index + 1]
            left_part_average //= (index + 1)
            
            right_part_average = suffix_sum[index + 1]
            if index != n - 1:
                right_part_average //= (n - index - 1)
            
            curr_difference = abs(left_part_average - right_part_average)
            
            if curr_difference < min_avg_diff:
                min_avg_diff = curr_difference
                ans = index
                
        return ans