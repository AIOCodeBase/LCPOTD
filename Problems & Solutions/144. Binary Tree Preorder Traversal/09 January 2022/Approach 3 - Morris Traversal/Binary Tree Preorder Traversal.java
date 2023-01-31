class Solution {    
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        TreeNode curr = root, last;
        
        while (curr != null) {
            if(curr.left == null) {
                answer.add(curr.val);
                curr = curr.right;
            } else {
                last = curr.left;
                while (last.right != null && last.right != curr) {
                    last = last.right;
                }

                if (last.right == null) {
                    answer.add(curr.val);
                    last.right = curr;
                    curr = curr.left;
                } else {
                    last.right = null;
                    curr = curr.right;
                }
            }
        }
        
        return answer;
    }
}