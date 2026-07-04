class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, vis, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        vector<int> erow = { 1, -1, 0, 0 };
        vector<int> ecol = { 0, 0, 1, -1 };

        for( int i = 0 ; i < 4 ; i++ ) {
            for( int j = 0 ; j < 4 ; j++ ) {

                int nrow = row + erow[i];
                int ncol = col + ecol[i];

                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    dfs(grid,vis,nrow,ncol);
                }


                
            }
        }
    }
};
