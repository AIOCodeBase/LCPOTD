class Solution {
    func shuffle(_ nums: [Int], _ n: Int) -> [Int] {
        var result = Array(repeating: 0, count: 2 * n)
        for i in 0..<n {
            result[2 * i] = nums[i]
            result[2 * i + 1] = nums[n + i]
        }
        return result
    }
}