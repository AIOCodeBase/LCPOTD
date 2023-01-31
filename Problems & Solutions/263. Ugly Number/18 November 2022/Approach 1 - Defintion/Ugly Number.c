bool isUgly(int n) {   
    // A non-positive integer cannot be ugly
    if (n <= 0) {
        return false;
    }

    // Factorize by dividing with permitted factors.
    int factors[] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        n = keepDividingWhenDivisible(n, factors[i]);
    }

    // Check if the integer is reduced to 1 or not.
    return n == 1;
}

// Keep dividing dividend by divisor when division is possible.
int keepDividingWhenDivisible(int dividend, int divisor) {
    while (dividend % divisor == 0) {
        dividend /= divisor;;
    }
    return dividend;
}