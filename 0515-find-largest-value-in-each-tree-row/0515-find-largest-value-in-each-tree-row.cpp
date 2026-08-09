class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return {}; 
        q.push(root);
        vector<int> ans;

        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            for( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = q.front();
                maxi = max(maxi,node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};