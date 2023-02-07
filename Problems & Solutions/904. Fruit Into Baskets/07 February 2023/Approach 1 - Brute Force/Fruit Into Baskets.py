class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        max_picked = 0
        
        for left in range(len(fruits)):
            for right in range(left, len(fruits)):
                basket = set()
                
                for current_index in range(left, right + 1):
                    basket.add(fruits[current_index])
                    
                if len(basket) <= 2:
                    max_picked = max(max_picked, right - left + 1)
        
        return max_picked