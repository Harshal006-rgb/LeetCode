
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int d = 0;

        while (!q.empty()) {

            int n = q.size();
            d++;

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (depth == d + 1) {
                    TreeNode* newleft = new TreeNode(val);
                    TreeNode* newright = new TreeNode(val);

                    if(node->left) newleft->left = node->left;
                    node->left = newleft;

                    if(node->right) newright->right = node->right;
                    node->right = newright;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return root;
    }
};