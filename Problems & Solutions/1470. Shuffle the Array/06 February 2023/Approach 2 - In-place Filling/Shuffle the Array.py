class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        for i in range(n, 2 * n):
            secondNum = nums[i] << 10
            nums[i - n] |= secondNum

        allOnes = int(pow(2, 10)) - 1

        for i in range(n - 1, -1, -1):
            secondNum = nums[i] >> 10
            firstNum = nums[i] & allOnes
            nums[2 * i + 1] = secondNum
            nums[2 * i] = firstNum
        return nums