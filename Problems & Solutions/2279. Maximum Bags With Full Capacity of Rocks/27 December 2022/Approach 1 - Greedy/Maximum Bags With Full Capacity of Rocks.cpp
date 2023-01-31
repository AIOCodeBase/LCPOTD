class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = int(capacity.size()), fullBags = 0;

        vector<int> remainingCapacity(n);

        for (int i = 0; i < n; ++i)
            remainingCapacity[i] = capacity[i] - rocks[i];
        sort(remainingCapacity.begin(), remainingCapacity.end());

        for (int i = 0; i < n; ++i) {
            if (additionalRocks >= remainingCapacity[i]) {
                additionalRocks -= remainingCapacity[i];
                fullBags++;
            }
            else {
                break;
            }
        }
        
        return fullBags;
    }
};