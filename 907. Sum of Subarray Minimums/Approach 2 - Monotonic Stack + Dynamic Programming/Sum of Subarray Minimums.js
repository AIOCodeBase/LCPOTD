let sumSubarrayMins = function (arr) {
    const MOD = 1000000007;
    let stack = [];
    
    let dp = new Array(arr.length).fill(0);

    for (let i = 0; i < arr.length; i++) {
        
        while (stack.length && arr[stack.at(-1)] >= arr[i]) {
            stack.pop();
        }

        if (stack.length) {
            const previousSmaller = stack.at(-1);
            dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i];
        } else {
            
            dp[i] = (i + 1) * arr[i];
        }
        stack.push(i);
    }

    const sumOfMinimums = dp.reduce((a, b) => a + b, 0);

    return sumOfMinimums % MOD;
};

