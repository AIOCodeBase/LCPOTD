class Solution {
    func minimumAverageDifference(_ nums: [Int]) -> Int {
        let n = nums.count
        var ans = -1
        var minAvgDiff = Int32.max
        
        for index in 0..<n {
            let leftPartAverage = nums[0...index].map{Int64($0)}.reduce(Int64(0), +) / Int64(index + 1)
            
            let rightPartAverage = nums[(index + 1)..<n].map{Int64($0)}.reduce(Int64(0), +)
            if (index != n - 1) {
                rightPartAverage /= Int64(n - index - 1)
            }
            
            let currDifference = abs(leftPartAverage - rightPartAverage)
            if (currDifference < minAvgDiff) {
                minAvgDiff = Int32(currDifference)
                ans = index
            }
        }
        
        return ans
    }
}