class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        dfs(root, 0, 0, mp);
        
        vector<vector<int>> ans;
        for (auto& colPair : mp) {
            vector<int> col;
            for (auto& rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
private:
    void dfs(TreeNode* node, int x, int y, map<int, map<int, multiset<int>>>& mp) {
        if (!node) return;
        mp[x][y].insert(node->val);
        dfs(node->left, x - 1, y + 1, mp);
        dfs(node->right, x + 1, y + 1, mp);
    }
};