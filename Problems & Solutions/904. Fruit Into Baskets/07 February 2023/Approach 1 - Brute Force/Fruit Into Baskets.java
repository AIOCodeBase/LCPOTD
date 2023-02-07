class Solution {
    public int totalFruit(int[] fruits) {
        int maxPicked = 0;
        
        for (int left = 0; left < fruits.length; ++left) {
            for (int right = 0; right < fruits.length; ++right) {
                Set<Integer> basket = new HashSet<>();
                
                for (int currentIndex = left; currentIndex <= right; ++currentIndex) {
                    basket.add(fruits[currentIndex]);
                }
                
                if (basket.size() <= 2) {
                    maxPicked = Math.max(maxPicked, right - left + 1);
                }
            }
        }
        
        return maxPicked;
    }
}