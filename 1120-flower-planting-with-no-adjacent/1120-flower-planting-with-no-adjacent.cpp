class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for( auto edge : paths ){
            int a = edge[0]-1;
            int b = edge[1]-1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n,-1);

        rec(adj,color,0);
        return color;
    }

    bool isPossible(int idx , vector<int> &color , vector<vector<int>> &adj , int i ){
        for( int edge : adj[idx]){
            if( color[edge] == i ) return false;
        }
        return true;
    }


    bool rec( vector<vector<int>> &adj , vector<int> &color , int idx ){
        int n = adj.size();
        if( idx == n ) return true;

        for( int i = 1 ; i <= 4 ; i++ ) {
            if( isPossible(idx,color,adj,i) ){
                color[idx] = i;
                if(rec(adj,color,idx+1)){
                    return true;
                }
                color[idx] = -1;

            }
            
        }
        return false;
    }
};