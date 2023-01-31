class Solution {
    func maxIceCream(_ costsArray: [Int], _ totalCoins: Int) -> Int {
        var coins = totalCoins
        var costs = costsArray

        costs.sort()

        let n: Int = costs.count
        var icecream: Int = 0

        while icecream < n && costs[icecream] <= coins {
            coins -= costs[icecream]
            icecream += 1
        }

        return icecream
    }
}