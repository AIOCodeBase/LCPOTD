let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;
    let currPrefixSum = 0;
        
    let totalSum = 0;
    for (let index = 0; index < n; ++index) {
        totalSum += nums[index];
    }
    
    for (let index = 0; index < n; ++index) {
        currPrefixSum += nums[index];
        
        let leftPartAverage = currPrefixSum;
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        let rightPartAverage = totalSum - currPrefixSum;
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