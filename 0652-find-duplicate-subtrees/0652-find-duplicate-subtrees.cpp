class Solution {
public:
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> result;
        dfs(root,result,mp);
        return result;
    }
        
    string dfs(TreeNode* root ,vector<TreeNode*> &result , unordered_map<string,int> &mp){
        if(!root) return "n";

        string s = to_string(root->val) + ','
        + dfs(root->left,result,mp) + ',' 
        + dfs(root->right,result,mp);

        mp[s]++;
        if( mp[s] == 2 ) result.push_back(root);
        return s;

    }
};