class Solution {
public:
    int helper(TreeNode* root, int &maxi) {
        if(!root) return 0;
        int l= helper(root->left, maxi);
        int r= helper(root->right, maxi);
        maxi=max(maxi,(l+r));
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};