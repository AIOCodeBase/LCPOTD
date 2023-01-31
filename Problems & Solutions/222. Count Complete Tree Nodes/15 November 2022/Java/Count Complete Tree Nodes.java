class Solution {
    public int countNodes(TreeNode root) 
    {
        if (root == null) return 0;

        TreeNode left = root, right = root;
        int l = 1, r = 1;
        
        while ((left  = left.left)   != null) ++l;
        while ((right = right.right) != null) ++r;
        
        if (l == r) return (1 << l) - 1;
        
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}