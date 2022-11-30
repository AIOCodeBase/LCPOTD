class Solution {
    final int K = 1000;
    
    public boolean uniqueOccurrences(int[] arr) {
        int freq[] = new int[2 * K + 1];
      
        for (int num : arr) {
            freq[num + K]++;
        }
        
        Arrays.sort(freq);
        
        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] != 0 && freq[i] == freq[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
}