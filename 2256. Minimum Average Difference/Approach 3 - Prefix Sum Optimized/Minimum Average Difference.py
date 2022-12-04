class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        min_avg_diff = math.inf
        curr_prefix_sum = 0
        
        # Get total sum of array.
        total_sum = 0
        for index in range(n):
            total_sum += nums[index]
        
        for index in range(n):
            curr_prefix_sum += nums[index]
            
            left_part_average = curr_prefix_sum
            left_part_average //= (index + 1)
            
            right_part_average = total_sum - curr_prefix_sum
            if index != n - 1:
                right_part_average //= (n - index - 1)
            
            curr_difference = abs(left_part_average - right_part_average)
            
            if curr_difference < min_avg_diff:
                min_avg_diff = curr_difference
                ans = index
                
        return ans