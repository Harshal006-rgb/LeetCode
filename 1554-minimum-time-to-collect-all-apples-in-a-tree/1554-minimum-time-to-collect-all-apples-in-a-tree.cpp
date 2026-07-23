class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for( auto edge : edges ){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int result =  dfs(adj,hasApple,-1,0);
        if( result ) return result - 2;
        return 0;
    }

    int dfs( vector<vector<int>> &adj,vector<bool>& hasApple, int parent,int node){
        int sum = 0;
        for( int edge : adj[node] ) {
            if( edge != parent){
                sum += dfs(adj,hasApple,node,edge);        
            }
        }
        if( sum || hasApple[node] ) return sum + 2;
        return 0;
    }
};