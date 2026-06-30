class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        unordered_map<int , int > mp;
        for( int i = 0 ; i < n ; i++ ) {
            mp[inorder[i]] = i;
        }

        int idx = 0;
        return solve(preorder,inorder,0,n-1,idx,mp);
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int l , int r , int &idx , unordered_map<int , int > &mp){
        if(l>r) return NULL;
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder,inorder,l,i-1,idx,mp);
        root->right = solve(preorder,inorder,i+1,r,idx,mp);
        return root;

    }
};