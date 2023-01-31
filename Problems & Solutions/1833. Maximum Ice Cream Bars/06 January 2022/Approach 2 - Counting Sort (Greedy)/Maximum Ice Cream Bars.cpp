class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int icecreams = 0;

        vector<int> costsFrequency(m + 1);
        for (auto& cost : costs) {
            costsFrequency[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost) {
            if (costsFrequency[cost] == 0) {
                continue;
            }
            if (coins < cost) {
                break;
            }
            
            int count = min(costsFrequency[cost], coins / cost);
            coins -= cost * count;
            icecreams += count;
        }

        return icecreams;
    }
};