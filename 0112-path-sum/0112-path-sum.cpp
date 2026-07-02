class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right){
            if(targetSum == root->val) return true;
            return false;
        }
        targetSum-=root->val;
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }

    // bool pathsum(TreeNode* node , int sum ){
    //     if(!node){
    //         if(sum == 0) return true;
    //         return false;
    //     }
    //     sum-=node->val;
    //     return pathsum(node->left,sum) || pathsum(node->right,sum);
    // }


};