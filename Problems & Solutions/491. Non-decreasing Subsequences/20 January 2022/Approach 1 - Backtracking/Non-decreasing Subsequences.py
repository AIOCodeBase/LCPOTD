class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        result = set()
        sequence = []

        def backtrack(index):
            if index == len(nums):
                if len(sequence) >= 2:
                    result.add(tuple(sequence))
                return
            if not sequence or sequence[-1] <= nums[index]:
                sequence.append(nums[index])
                backtrack(index + 1)
                sequence.pop()
            backtrack(index + 1)
        backtrack(0)
        return result