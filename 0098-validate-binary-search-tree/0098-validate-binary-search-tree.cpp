class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        return preorder(root, mini, maxi);
    }

    bool preorder(TreeNode *root, long mini, long maxi)
    {
        if (!root) return true;
        if (root->val <= mini || root->val >= maxi) return false;
        return preorder(root->left, mini, root->val) &&
               preorder(root->right, root->val, maxi);
    }
};