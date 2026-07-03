class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool seen = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node->left) seen = true;
            else{
                if(seen) return false;
                q.push(node->left);
            }
            if(!node->right) seen = true;
            else{
                if(seen) return false;
                q.push(node->right);
            }
            
        }

        return true;
    }
};