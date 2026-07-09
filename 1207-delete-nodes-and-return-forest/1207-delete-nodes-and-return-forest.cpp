class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> mp;
        for( int del : to_delete ) mp[del]++;

        vector<TreeNode*> trees;
        if(root && !mp[root->val]) trees.push_back(root);

        dfs(root,mp,trees);

        return trees;
    }

    void dfs(TreeNode* node , unordered_map<int,int> &mp , vector<TreeNode*> &trees ){
        if(!node) return;

        if(mp[node->val]){
            if(node->left && !mp[node->left->val]) trees.push_back(node->left);
            if(node->right && !mp[node->right->val]) trees.push_back(node->right);
        }

        if(node->left){
            dfs(node->left,mp,trees);
            if(mp[node->left->val]){
                node->left= NULL;
            }
        }
        if(node->right){
            dfs(node->right,mp,trees);
            if(mp[node->right->val]){
                node->right= NULL;
            }
        }
        
    }
};