class Solution {
    public String makeGood(String s) {
        StringBuilder newS = new StringBuilder(s);
        
        // if s has less than 2 characters, we just return itself.
        while (newS.length() > 1) {
            // 'find' records if we find any pair to remove.
            boolean find = false;
            
            // Check every two adjacent characters, currChar and nextChar.
            for (int i = 0; i < newS.length() - 1; ++i) {
                char currChar = newS.charAt(i), nextChar = newS.charAt(i + 1);
                
                // If they make a pair, remove them from 's' and let 'find = true'.
                if (Math.abs(currChar - nextChar) == 32) {
                    newS.deleteCharAt(i);
                    newS.deleteCharAt(i);
                    find = true;
                    break;
                }
            }
            
            // If we cannot find any pair to remove, break the loop. 
            if (!find)
                break;
        }
        return newS.toString();
    }
}