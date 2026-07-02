class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1,root2);
    }

    TreeNode* merge(TreeNode* node1, TreeNode* node2){
        
        if(!node1 && !node2) return NULL;
        else if(!node1) return node2;
        else if(!node2) return node1;

        TreeNode* node = new TreeNode(node1->val + node2->val);
        node->left = merge(node1->left,node2->left);
        node->right = merge(node1->right,node2->right);

        return node;
    }
};