class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);

        int n = costs.length;
        int icecream = 0;

        while (icecream < n && costs[icecream] <= coins) {
            coins -= costs[icecream];
            icecream += 1;
        }

        return icecream;
    }
}