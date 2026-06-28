class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        ok(root,maxi);
        return maxi;
    }

    int ok( TreeNode* root , int & maxi ){
        if( root == NULL ) return 0;

        int l = ok(root->left, maxi);
        int r = ok(root->right, maxi);
        
        maxi = max( maxi , root->val + l + r );
        return max(0, root->val + max(l,r) ); 
    }
};