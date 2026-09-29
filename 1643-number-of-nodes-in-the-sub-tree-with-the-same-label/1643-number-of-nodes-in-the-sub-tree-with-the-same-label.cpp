class Solution {
public:

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>> adj(n);
        for( auto edge : edges ) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<vector<int>> letter(n,vector<int>(26,0));
        vector<int> ans(n,0);

        rec( 0 , -1 , ans, letter , labels , adj);
        return ans;
    }


    void rec( int i , int parent , vector<int> & ans ,vector<vector<int>> & letter , string & labels ,vector<vector<int>>& adj ){

        for( int edge : adj[i] ) {
            if( edge == parent ) continue;
            rec( edge , i , ans , letter , labels , adj);     
            for( int j = 0 ; j < 26 ; j++ ) {
                letter[i][j] += letter[edge][j];
            }       
        }
        letter[i][labels[i]-'a']++;
        ans[i] = letter[i][labels[i]-'a'];
    }
};