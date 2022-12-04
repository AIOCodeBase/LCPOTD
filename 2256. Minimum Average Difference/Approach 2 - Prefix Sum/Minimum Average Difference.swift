class Solution {
    func minimumAverageDifference(_ nums: [Int]) -> Int {
        let n = nums.count
        var ans = -1
        var minAvgDiff = Int32.max
        
        var prefixSum = [Int64](repeating: 0, count: n + 1)
        var suffixSum = [Int64](repeating: 0, count: n + 1)
        
        for index in 0..<n {
            prefixSum[index + 1] = prefixSum[index] + Int64(nums[index])
        }
        
        for index in (0..<n).reversed() {
            suffixSum[index] = suffixSum[index + 1] + Int64(nums[index])
        }
        
        for index in 0..<n {
            var leftPartAverage = prefixSum[index + 1]
            leftPartAverage /= Int64(index + 1)
            
            var rightPartAverage = suffixSum[index + 1]
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