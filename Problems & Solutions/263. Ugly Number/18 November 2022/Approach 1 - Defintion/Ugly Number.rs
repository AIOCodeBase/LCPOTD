impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        // A non-positive integer cannot be ugly
        if n <= 0 {
            return false;
        }

        let mut n = n;

        // Factorize by dividing with permitted factors.
        for factor in [2, 3, 5] {
            n = Self::keep_dividing_when_divisible(n, factor);
        }

        // Check if the integer is reduced to 1 or not.
        return n == 1;
    }

    // Keep dividing dividend by divisor when division is possible.
    fn keep_dividing_when_divisible(mut dividend: i32, divisor: i32) -> i32 {
        while dividend % divisor == 0 {
            dividend /= divisor;;
        }
        return dividend;
    }
}