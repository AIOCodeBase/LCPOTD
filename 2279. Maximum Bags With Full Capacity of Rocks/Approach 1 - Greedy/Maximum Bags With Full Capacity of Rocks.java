class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = capacity.length, fullBags = 0;
        
        int[] remainingCapacity = new int[n];
        for (int i = 0; i < n; ++i)
            remainingCapacity[i] = capacity[i] - rocks[i];
        Arrays.sort(remainingCapacity);
    
        for (int i = 0; i < n; ++i) {
            if (additionalRocks >= remainingCapacity[i]) {
                additionalRocks -= remainingCapacity[i];
                fullBags++;
            }
            else
                break;
        }
        
        return fullBags;
    }
}