class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        TreeNode* curr = root;
        TreeNode* last;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                answer.push_back(curr->val);
                curr = curr->right;
            } else {
                last = curr->left;
                while (last->right != nullptr && last->right != curr) {
                    last = last->right;
                }
                
                if (last->right == nullptr) {
                    answer.push_back(curr->val);
                    last->right = curr;
                    curr = curr->left;
                } else {
                    last->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        
        return answer;
    }
};