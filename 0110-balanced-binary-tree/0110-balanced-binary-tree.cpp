/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:

    int maxlength( TreeNode* root ){
        if( root == NULL ) return 0;
        int l = maxlength( root -> left);
        int r = maxlength( root -> right);
        
        //check for left , right with length
        if( abs(l-r) > 1 ||  r == -1 || l == -1 ) return -1;

        return 1 + max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        return maxlength(root) != -1;
    }

};