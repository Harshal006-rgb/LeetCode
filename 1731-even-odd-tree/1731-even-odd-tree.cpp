class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        bool even = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int prev;

            if( even ) prev = -1;
            else prev = INT_MAX;

            for( int i = 0 ; i < n ; i++ ) {

                TreeNode* node = q.front();
                q.pop();

                if( even && (node->val%2 == 0 || prev >= node->val) ) return false;
                if( !even && (node->val%2 != 0 || prev <= node->val) ) return false;

                if( node->left ) q.push(node->left);
                if( node->right ) q.push(node->right);

                prev = node->val;

            }

            if( even ) even = false;
            else even = true;
        }

        return true;
    }
};