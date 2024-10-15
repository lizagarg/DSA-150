class Solution {
public:
    int check(TreeNode* root) {
        if(!root) return 0;

        int l= check(root->left);
        if(l==-1) return -1;
        int r= check(root->right);
        if(r==-1) return -1;

        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};