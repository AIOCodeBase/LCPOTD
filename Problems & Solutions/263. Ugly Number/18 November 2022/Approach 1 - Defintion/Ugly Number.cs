public class Solution {
    public bool IsUgly(int n) {        
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }
        
        // Factorize by dividing with permitted factors.
        foreach (int factor in new int[] {2, 3, 5}) {
            n = KeepDividingWhenDivisible(n, factor);
        }

        // Check if the integer is reduced to 1 or not.
        return n == 1;
    }
    
    // Keep dividing dividend by divisor when division is possible.
    int KeepDividingWhenDivisible(int dividend, int divisor) {
        while (dividend % divisor == 0) {
            dividend /= divisor;;
        }
        return dividend;
    }
}