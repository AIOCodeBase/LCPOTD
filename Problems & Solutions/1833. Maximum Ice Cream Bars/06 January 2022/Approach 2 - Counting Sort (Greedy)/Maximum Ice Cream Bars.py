class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        n, icecreams = len(costs), 0
        m = max(costs)

        costsFrequency = [0] * (m + 1)
        for cost in costs:
            costsFrequency[cost] += 1

        for cost in range(1, m + 1):
            if not costsFrequency[cost]:
                continue
            if coins < cost:
                break
            
            count = min(costsFrequency[cost], coins // cost)
            coins -= cost * count
            icecreams += count
            
        return icecreams