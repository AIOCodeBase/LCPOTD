class Solution {
public:
    int countOdds(int low, int high) {
        if (!(low & 1)) {
            low++;
        }
  
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};