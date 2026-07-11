class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        return dfs(root);
    }

    TreeNode* dfs( TreeNode* root ){
        if(!root) return NULL;


        TreeNode* l = NULL;
        TreeNode* r = NULL;

        if(root->left){
            l = dfs(root->left);
        }
        if(root->right){
            r = dfs(root->right);
        }

        root->left = l;
        root->right= r;

        if( l || r || root->val == 1){
            return root;
        }
        return NULL;

    }
};