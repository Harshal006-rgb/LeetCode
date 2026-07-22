class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    int target;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph,0);
        return res;
    }

    void dfs(vector<vector<int>>& graph , int node ){
        temp.push_back(node);
        if( target == node) res.push_back(temp);
        else{
            for( int newnode : graph[node] ){
                dfs(graph,newnode);
            }
        }
        temp.pop_back();
    }
};