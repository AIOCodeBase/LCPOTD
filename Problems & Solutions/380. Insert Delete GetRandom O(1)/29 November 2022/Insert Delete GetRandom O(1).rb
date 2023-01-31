class RandomizedSet
    def initialize()
        @hash = Hash.new
        @nums = Array.new
    end
    def insert(val)
        return false if @hash.key?(val)
        @nums << val
        @hash[val] = @nums.size - 1
        true
    end
    def remove(val)
        return false unless @hash.key?(val)
        @hash[@nums.last] = @hash[val] if val != @nums.last
        @nums[@hash[val]] = @nums.last
        @nums.delete_at(@nums.size - 1)
        @hash.delete(val)
        true
    end
    def get_random()
        @nums[rand(@nums.size)]
    end
end