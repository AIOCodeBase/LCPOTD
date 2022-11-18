/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function(n) {    
    // A non-positive integer cannot be ugly
    if (n <= 0) {
        return false;
    }
    
    // Keep dividing dividend by divisor when division is possible.
    const keepDividingWhenDivisible = (dividend, divisor) => {
        while (dividend % divisor == 0) {
            dividend /= divisor;;
        }
        return dividend;
    }

    // Factorize by dividing with permitted factors.
    for (const factor of [2, 3, 5]) {
        n = keepDividingWhenDivisible(n, factor);
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1;
};