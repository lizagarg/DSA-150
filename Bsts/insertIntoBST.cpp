class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //recursive
        if(!root) return new TreeNode(val);

        if(val>root->val) root->right= insertIntoBST(root->right,val);
        else root->left= insertIntoBST(root->left, val);

        return root;
    }
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //iterative
        if(!root) return new TreeNode(val);
        TreeNode* curr= root;

        while(true) {
            if(val>=curr->val) {
                if(curr->right!=nullptr) curr=curr->right;
                else {
                    curr->right= new TreeNode(val);
                    break;
                }
            } else {
                if(curr->left!=nullptr) curr=curr->left;
                else{
                    curr->left= new TreeNode(val);
                    break;
                } 
            }
        }
        return root;
    }
};