let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;

    for (let index = 0; index < n; ++index) {
        let leftPartAverage = 0;
        for (let i = 0; i <= index; ++i) {
            leftPartAverage += nums[i];
        }
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        let rightPartAverage = 0;
        for (let j = index + 1; j < n; ++j) {
            rightPartAverage += nums[j];
        }
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