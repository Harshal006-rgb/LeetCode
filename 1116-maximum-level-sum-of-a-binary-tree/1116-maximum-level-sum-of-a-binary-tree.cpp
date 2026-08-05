class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxi = 0;
        int level = 0;
        int maxisum = INT_MIN;
        
        while(!q.empty()){
            int n = q.size();
            int levelsum = 0;
            level++;

            for( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = q.front();
                levelsum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            if( maxisum < levelsum ){
                maxisum = levelsum;
                maxi = level;
            }

        }

        return maxi;
    }
};