class Solution {
    func minimumAverageDifference(_ nums: [Int]) -> Int {
        let n = nums.count
        var ans = -1
        var minAvgDiff = Int32.max
        var currPrefixSum: Int64 = 0
        
        var totalSum: Int64 = 0
        for index in 0..<n {
            totalSum += Int64(nums[index])
        }
        
        for index in 0..<n {
            currPrefixSum += Int64(nums[index])
            
            var leftPartAverage = currPrefixSum
            leftPartAverage /= Int64(index + 1)
            
            var rightPartAverage = totalSum - currPrefixSum
            if (index != n - 1) {
                rightPartAverage /= Int64(n - index - 1)
            }
            
            let currDifference = abs(leftPartAverage - rightPartAverage)
            if (currDifference < minAvgDiff) {
                minAvgDiff = Int32(currDifference)
                ans = index
            }
        }
        
        return ans;
    }
}