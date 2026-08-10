
class Solution {
public:
    int steps = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }

    int dfs( TreeNode* node){
        if(!node) return 0;

        int leftReq = dfs(node->left);
        int rightReq = dfs(node->right);

        steps += abs(leftReq) + abs(rightReq);
        return (node->val-1) + leftReq + rightReq;
    }
};