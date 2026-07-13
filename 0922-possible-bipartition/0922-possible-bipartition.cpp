class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for( auto dislike : dislikes) {
            int a = dislike[0];
            int b = dislike[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n+1,-1);

        for( int i = 1 ; i <= n ; i++ ) {
            if(color[i] == -1 ){
                if(!bfs(i,adj,color)) return false;
            }
        }

        return true;
    }

    bool bfs(int i , vector<vector<int>> &adj , vector<int> &color){
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for( int edge : adj[node] ) {
                if(color[edge] == -1){
                    q.push(edge);
                    color[edge] = color[node]==1?0:1;
                }
                else if( color[edge] == color[node]) return false;               
            }
        }

        return true;
    }
};