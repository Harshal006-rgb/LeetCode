
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);

        for( int i = 0 ; i < n-1 ; i++ ) {
            for( int j = i+1 ; j < n ; j++ ) {
                if( stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);

        int grp = 0;

        for( int i = 0 ; i < n ; i++ ) {
            if(!vis[i]){
                dfs(i,adj,vis);
                grp++;
            }
        }

        return n-grp;
    }

    void dfs( int i , vector<vector<int>> &adj ,vector<int> &vis){
        vis[i] = 1;
        for( int idx : adj[i] ){
            if(!vis[idx]){
                dfs(idx,adj,vis);
            }
        } 
    }
};