class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //to collect parent nodes
        unordered_map<TreeNode*,TreeNode*> parent;
        getparent(root,parent);



        //using bfs 
        return getkdist(target,k,parent);
        
    }
    
    vector<int> getkdist( TreeNode* target , int k , unordered_map<TreeNode*,TreeNode*> &parent ){
        unordered_set<TreeNode*> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int count = 0;

        while(!q.empty()){
            int size = q.size();

            if(count++ == k) break;

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

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
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