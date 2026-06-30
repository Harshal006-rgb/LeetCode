class Solution {
public:


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n = postorder.size();
        int inStart = 0 , postStart = 0;
        int inEnd = n-1 , postEnd = n-1;
        for( int i = 0 ; i < n ; i++ ) {
            mp[inorder[i]] = i;
        }
        
        return solve(inorder,postorder,inStart,inEnd,postStart,postEnd,mp);
    }


    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd , unordered_map<int,int> &mp){
        if(inStart>inEnd || postStart>postEnd) return NULL;


        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inroot = mp[root->val];
        int leftsize = inroot-inStart;
        int rightsize = inEnd-inroot;

        
        root->left = solve(inorder,postorder,inStart,inroot-1,postStart,postStart+leftsize-1,mp);
        root->right = solve(inorder,postorder,inroot+1,inEnd,postStart+leftsize,postEnd-1,mp);

        return root;



    }
};