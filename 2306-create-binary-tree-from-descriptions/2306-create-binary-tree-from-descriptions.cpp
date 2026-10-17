class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        int n = descriptions.size();
        unordered_map<int,int> l;
        unordered_map<int,int> r;
        unordered_set<int> children;


        for( int i = 0 ; i < n ; i++ ) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int left = descriptions[i][2];

            if(left) l[parent] = child;
            else r[parent] = child;
            
            children.insert(child);
        }
        
        int rootval;

        for( auto ok : descriptions ){
            int parent = ok[0];

            if(!children.count(parent)){
                rootval = parent; 
                break;
            }
        }

        return treemaker(rootval,l,r);        
    }

    TreeNode* treemaker( int rootval , unordered_map<int,int> &l , unordered_map<int,int> &r ){

        TreeNode* root = new TreeNode(rootval);

        if( l.count(root->val)){
            root->left = treemaker(l[root->val],l,r);
        }
        if( r.count(root->val)){
            root->right = treemaker(r[root->val],l,r);
        }

        return root;

    }
};