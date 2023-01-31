class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int n = costs.size();
        int icecream = 0;

        while (icecream < n && costs[icecream] <= coins) {
            coins -= costs[icecream];
            icecream += 1;
        }

        return icecream;
    }
};