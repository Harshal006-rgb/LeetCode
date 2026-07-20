class Solution {
public:
    long long prd = 1;
    int sum = 0;
    bool flag = false;
    int maxProduct(TreeNode* root) {
        prd = 1;
        sum = 0;
        sum = getsum(root);
        flag = true;
        getsum(root);
        return prd % 1000000007;
    }

    int getsum(TreeNode* root){
        if(!root) return 0;

        int left = 0;
        int right = 0;
        if(root->left) left = getsum(root->left);
        if(root->right) right = getsum(root->right);

        if( flag ){
            prd = max(prd, (long long)left*(sum-left));
            prd = max(prd, (long long)right*(sum-right));
        }
        return left + right + root->val;
    }
};