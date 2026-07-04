class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if(i==j) continue;
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs( vector<vector<int>> &adj ,vector<int> &vis , int node ){
    vis[node] = 1;

    for( int edge : adj[node] ) {
        if(!vis[edge])
        dfs(adj,vis,edge);
    }
}

};

