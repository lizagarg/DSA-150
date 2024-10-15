class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()) {
            auto p= q.front();
            q.pop();
            TreeNode* node= p.first;
            int v= p.second.first;
            int lvl= p.second.second;
            mp[v][lvl].insert(node->val);

            if(node->left) q.push({node->left,{v-1,lvl+1}});
            if(node->right) q.push({node->right,{v+1,lvl+1}});
        }

        for(auto i: mp) {
            vector<int>verticals;
            for(auto p:i.second) {
                verticals.insert(verticals.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(verticals);
        }

        return ans;
    }
};