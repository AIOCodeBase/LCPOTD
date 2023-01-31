let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;

    let prefixSum = Array(n + 1).fill(0);
    let suffixSum = Array(n + 1).fill(0);
    
    for (let index = 0; index < n; ++index) {
        prefixSum[index + 1] = prefixSum[index] + nums[index];
    }

    for (let index = n - 1; index >= 0; --index) {
        suffixSum[index] = suffixSum[index + 1] + nums[index];
    }
    
    for (let index = 0; index < n; ++index) {
        let leftPartAverage = prefixSum[index + 1];
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        let rightPartAverage = suffixSum[index + 1];
        if (index != n - 1) {
            rightPartAverage = Math.floor(rightPartAverage / (n - index - 1));
        }

        let currDifference = Math.abs(leftPartAverage - rightPartAverage);
        if (currDifference < minAvgDiff) {
            minAvgDiff = currDifference;
            ans = index;
        }
    }

    return ans;
};