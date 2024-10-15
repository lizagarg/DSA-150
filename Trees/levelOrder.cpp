class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int size= q.size();
            vector<int>level;
            for(int i=0;i<size;i++) {
                TreeNode* popped= q.front();
                q.pop();
                if(popped->left) q.push(popped->left);
                if(popped->right) q.push(popped->right);
                level.push_back(popped->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};