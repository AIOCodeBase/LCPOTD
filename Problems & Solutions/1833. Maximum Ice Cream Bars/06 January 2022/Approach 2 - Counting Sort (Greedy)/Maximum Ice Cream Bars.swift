class Solution {
    func maxIceCream(_ costs: [Int], _ totalCoins: Int) -> Int {
        let n: Int = costs.count
        var icecreams: Int = 0
        var coins: Int = totalCoins
        let m: Int = costs.max()!

        var costsFrequency: [Int] = [Int](repeating: 0, count: (m + 1))
        for cost in costs {
            costsFrequency[cost] += 1
        }

        for cost in 1...m {
            guard costsFrequency[cost] != 0 else {
                continue
            }
            guard coins >= cost else {
                break
            }
            
            let count: Int = min(costsFrequency[cost], coins / cost)
            coins -= cost * count
            icecreams += count
        }

        return icecreams
    }
}