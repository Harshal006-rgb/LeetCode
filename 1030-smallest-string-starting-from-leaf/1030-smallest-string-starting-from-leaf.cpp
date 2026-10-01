class Solution {
public:
    string result =  "";

    string smallestFromLeaf(TreeNode* root) {
        solve( root , "" );
        return result;
    }

    void solve( TreeNode* node , string curr ){
        if(!node) return;
        curr = char( 'a' + node->val ) + curr ;
        if( !node->left && !node->right ){
            if( result == "" || result > curr ) result = curr;
        }
        if(node->left) solve(node->left,curr);
        if(node->right) solve(node->right,curr);

    }


};