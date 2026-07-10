class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for( auto edge : edges ){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n,0);
        vector<long long> cnts;

        for( int i = 0 ; i < n ; i++ ) {
            if(!vis[i]){
                long long cnt = 1;
                dfs(adj,vis,cnt,i);
                cnts.push_back(cnt);
            }
        }

        if( cnts.size() <= 1) return 0;

        long long ans = 0;

        for( int i = 0 ; i < cnts.size() ; i++ ) {
            ans += (long long)cnts[i]*(n-cnts[i]);
           
        }

        return ans/2;



    }

    void dfs(vector<vector<int>> &adj , vector<int> &vis , long long &cnt , int node ){
        vis[node] = 1;
        for( int edge : adj[node]){
            if(!vis[edge]){
                cnt++;
                dfs(adj,vis,cnt,edge);
            }
        }
    }
};