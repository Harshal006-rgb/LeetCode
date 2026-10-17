
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        int n = descriptions.size();
        unordered_map<int,int> l;
        unordered_map<int,int> r;
        unordered_map<int,int> p;
        set<int> st;


        for( int i = 0 ; i < n ; i++ ) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int left = descriptions[i][2];

            if(left) l[parent] = child;
            else r[parent] = child;
            p[child] = parent;   
            st.insert(child);
            st.insert(parent);          
        }
        
        int rootval ;
        for( int num : st ){
            if(p.find(num) == p.end()){
                rootval = num; 
                break;
            }
        }
        return treemaker(rootval,l,r);        
    }

    TreeNode* treemaker( int rootval , unordered_map<int,int> &l , unordered_map<int,int> &r ){

        TreeNode* root = new TreeNode(rootval);

        TreeNode* leftnode = nullptr;
        TreeNode* rightnode = nullptr;

        if( l.find(root->val) != l.end() ){
            leftnode = treemaker(l[root->val],l,r);
        }
        if( r.find(root->val) != r.end()  ){
            rightnode = treemaker(r[root->val],l,r);
        }
        
        root->left = leftnode;
        root->right = rightnode;
        
        return root;

    }
};