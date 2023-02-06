var shuffle = function(nums, n) {
    let result = Array(2 * n);
    for (let i = 0; i < n; ++i) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }
    return result;
};