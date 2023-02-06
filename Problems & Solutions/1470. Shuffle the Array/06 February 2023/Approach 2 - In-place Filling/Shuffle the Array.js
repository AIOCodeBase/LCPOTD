var shuffle = function(nums, n) {
    for (let i = n; i < 2 * n; ++i) {
        let secondNum = nums[i] << 10;
        nums[i - n] |= secondNum;
    }

    let allOnes = Number(Math.pow(2, 10)) - 1;

    for (let i = n - 1; i >= 0; --i) {
        let secondNum = nums[i] >> 10;
        let firstNum = nums[i] & allOnes;
        nums[2 * i + 1] = secondNum;
        nums[2 * i] = firstNum;
    }
    return nums;
};