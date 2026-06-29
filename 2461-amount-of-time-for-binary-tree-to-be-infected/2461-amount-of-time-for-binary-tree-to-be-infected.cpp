class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        //to collect parent nodes
        unordered_map<TreeNode*,TreeNode*> parent;
        getparent(root,parent);

        TreeNode* target = gettarget(root,start);

        //using bfs 
        return gettime(target,parent);
        
    }

    TreeNode* gettarget(TreeNode* root, int start){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) return node;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return NULL;
    }

    int gettime( TreeNode* target ,unordered_map<TreeNode*,TreeNode*> &parent ){
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int count = -1;

        while(!q.empty()){
            int size = q.size();
            count++;

            for( int i = 0 ; i < size ; i++ ) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                //parent
                if( parent[node] && visited.find(parent[node]) == visited.end()){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
        }

        return count;
    }

    

    void getparent(TreeNode* root ,unordered_map<TreeNode*,TreeNode*> &parent ){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node; 
                q.push(node->left);
            } 
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }


};