class Solution {
public:
    vector<int> inorderNodes;
    
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);
        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        int minDistance = INT_MAX;
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDistance = min(minDistance, inorderNodes[i] - inorderNodes[i - 1]);
        }
        
        return minDistance;
    }
};
