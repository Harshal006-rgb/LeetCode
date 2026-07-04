class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ones = 0;

        queue<pair<pair<int, int>,int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                if( grid[i][j] == 1){
                    ones++;
                }
            }
        }

        int ans = 0;

        int convertedones = 0;

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            ans = max(ans,time);
            q.pop();
            vector<int> erow = {1, -1, 0, 0};
            vector<int> ecol = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + erow[i];
                int ncol = col + ecol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol},time+1});
                    convertedones++;
                }
            }
        }

        if(convertedones == ones){
            return ans;
        }
        return -1;



    }

};
