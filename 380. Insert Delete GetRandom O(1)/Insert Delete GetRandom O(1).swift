final class RandomizedSet {
    var hashMap = [Int: Int]()
    var arr = [Int]()
    
    init() {
        
    }
    
    func insert(_ val: Int) -> Bool {
        if hashMap[val] != nil {
            return false
        }
        arr.append(val)
        hashMap[val] = arr.count - 1
        return true
    }
    
    func remove(_ val: Int) -> Bool {
        if hashMap[val] == nil {
            return false
        }
        let index = hashMap[val]!
        let lastVal = arr.last!
        arr.swapAt(index, arr.count - 1)
        hashMap[lastVal] = index
        arr.removeLast()
        hashMap.removeValue(forKey: val)
        return true
    }

    func getRandom() -> Int {
        return arr.randomElement()!
    }
}