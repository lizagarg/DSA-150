class Solution {
public:
    int helper(TreeNode* root, int &maxi) {
        if(!root) return 0;
        int l= max(0,helper(root->left, maxi));
        int r= max(0,helper(root->right, maxi));
        maxi=max(maxi,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};