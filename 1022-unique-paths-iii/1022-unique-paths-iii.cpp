class Solution {
public:
    int ans = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        ans = 0;
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> start;
        
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( grid[i][j] == 0 ) cnt++;     
                else if( grid[i][j] == 1) start = {i,j};         
            }
        }
        int i = start.first;
        int j = start.second;
        rec(grid,cnt,i,j);
        return ans;
    }

    void rec( vector<vector<int>>& grid , int cnt , int row , int col){
        int n = grid.size();
        int m = grid[0].size();
        
        if(row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == -1) return;

        if( grid[row][col] == 0 ) cnt--;

        if( grid[row][col] == 2 ){
            if( cnt == 0){
                ans++;
            }
            return ;
        }

        int temp = grid[row][col] ;
        grid[row][col] = -1;

        vector<int> erow = {0,0,-1,1,};
        vector<int> ecol = {1,-1,0,0};

        for( int i = 0 ; i < 4 ; i++ ) {
            int nrow = erow[i]+row;
            int ncol = ecol[i]+col;

            rec(grid,cnt,nrow,ncol);
        }

        grid[row][col] = temp;
    }
};