class Solution {
public:
    int cnt = 0;
    int longestZigZag(TreeNode* root) {
        cnt = 0;
        dfs(root,'n',0);
        return cnt;
    }

    void dfs( TreeNode*root , char ch , int zz ){
        if(!root) return;

        if(root->left) {
            int zz1 = 1;
            if( ch != 'l' ) zz1 += zz;
            dfs(root->left,'l',zz1);
        }
        if(root->right){
            int zz1 = 1;
            if( ch != 'r' ) zz1 += zz;
            dfs(root->right,'r',zz1);
        }
        cnt = max(cnt,zz);

    }
};