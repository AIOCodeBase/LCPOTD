let sumSubarrayMins = function (arr) {
    const MOD = 1000000007;

    let stack = [];
    let sumOfMinimums = 0;

    for (let i = 0; i <= arr.length; i++) {

        while (stack.length && (i == arr.length || arr[stack.at(-1)] >= arr[i])) {

            const mid = stack.pop();
            const leftBoundary = stack.at(-1) === undefined ? -1 : stack.at(-1);
            const rightBoundary = i;

            const count = ((mid - leftBoundary) * (rightBoundary - mid)) % MOD;
            sumOfMinimums += (count * arr[mid]) % MOD;
            sumOfMinimums %= MOD;
        }
        stack.push(i);
    }
    
    return sumOfMinimums;
};

