class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        dis[0][0] = 1;

        vector<int> erow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> ecol = {-1, 0, 1, -1, 1, -1, 0, 1};


        while(!q.empty()){
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            
            q.pop();

            for( int i = 0 ; i < 8 ; i++ ) {

                int nrow = row + erow[i];
                int ncol = col + ecol[i];
                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 ){
                    if(dis[nrow][ncol] > dis[row][col] + 1){
                        dis[nrow][ncol] = dis[row][col] + 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        if(dis[n-1][m-1] == INT_MAX) return -1;
        return dis[n-1][m-1];

    }
};
