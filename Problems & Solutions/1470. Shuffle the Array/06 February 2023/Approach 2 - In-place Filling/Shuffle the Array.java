class Solution {
    public int[] shuffle(int[] nums, int n) {
        for (int i = n; i < 2 * n; ++i) {
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }

        int allOnes = (int) Math.pow(2, 10) - 1;

        for (int i = n - 1; i >= 0; --i) {
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            nums[2 * i + 1] = secondNum;
            nums[2 * i] = firstNum;
        }
        return nums;
    }
}