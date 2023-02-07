class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxPicked = 0;
        
        for (int left = 0; left < fruits.size(); ++left) {
            for (int right = 0; right < fruits.size(); ++right) {
                set<int> basket;
                
                for (int currentIndex = left; currentIndex <= right; ++currentIndex) {
                    basket.insert(fruits[currentIndex]);
                }
                
                if (basket.size() <= 2) {
                    maxPicked = max(maxPicked, right - left + 1);
                }
            }
        }
        
        return maxPicked;
    }
};