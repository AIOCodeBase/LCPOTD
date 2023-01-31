class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        
        answer = []
        
        for query in queries:
            index = bisect.bisect_right(nums, query)
            answer.append(index)
            
        return answer