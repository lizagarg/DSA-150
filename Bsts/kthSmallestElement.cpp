class Solution {
public:
    vector<int> ans;
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return ans[k-1];
    }
};