class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        n, icecream = len(costs), 0

        while icecream < n and costs[icecream] <= coins:
            coins -= costs[icecream]
            icecream += 1

        return icecream