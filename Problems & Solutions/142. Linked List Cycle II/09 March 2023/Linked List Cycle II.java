public class Solution {
    public ListNode detectCycle(ListNode head) {
        HashSet<ListNode> memo = new HashSet<>();

        ListNode curr = head;
        while (curr != null) {
            if (!memo.add(curr)) {
                return curr;
            }
            curr = curr.next;
        }
        
        return null;
    }
}