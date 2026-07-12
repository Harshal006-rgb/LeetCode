class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int steps = 0;
        
        int n = maze.size();
        int m = maze[0].size();
        
        vector<int> erow = {0,0,-1,1};
        vector<int> ecol = {-1,1,0,0};
        
        vector<vector<int>> vis(n,vector<int>(m,0));\

        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            int size = q.size();
            steps++;

            for( int i = 0 ; i < size ; i++ ) {
                int cellr = q.front().first;
                int cellc = q.front().second;
                q.pop();

                for( int j = 0 ; j < 4 ; j++ ) {
                    int nrow = cellr + erow[j];
                    int ncol = cellc + ecol[j];
                    if( nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && maze[nrow][ncol] == '.' && !vis[nrow][ncol]){
                        if( nrow == n-1 || ncol == 0 || nrow == 0 || ncol == m-1) return steps;
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }


        }

        return -1;
        
    }
};