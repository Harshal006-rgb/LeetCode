class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN;
        int a = root->val;
        int b = a;
        dfs(root,maxi,a,b);
        return maxi;
    }

    void dfs(TreeNode* root , int & maxi , int a  , int b){
        if(!root) return;
        a = max(a,root->val);
        b = min(b,root->val);
        
        if(root->left){
            maxi = max(maxi , abs(a - root->left->val));
            maxi = max(maxi , abs(b - root->left->val));
            dfs(root->left,maxi,a,b);
        }
        if(root->right){
            maxi = max(maxi , abs(a - root->right->val));
            maxi = max(maxi , abs(b - root->right->val));
            dfs(root->right,maxi,a,b);
        }

    }
};