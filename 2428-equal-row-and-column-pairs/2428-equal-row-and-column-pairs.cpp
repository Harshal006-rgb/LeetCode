
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row,col;
        int n = grid.size();

        for( int i = 0 ; i < n ; i++ ) {
            string s;
            for( int j = 0 ; j < n ; j++ ) {
                s+= to_string(grid[i][j])+",";
            }
            row[s]++;
        }

        int cnt = 0;

        for( int i = 0 ; i < n ; i++ ) {
            string s;
            for( int j = 0 ; j < n ; j++ ) {
                s+= to_string(grid[j][i])+",";
            }
            cnt+= row[s];
        }
        
        return cnt;
    }
};