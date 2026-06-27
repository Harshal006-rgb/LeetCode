class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(dfs(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs( int idx , int i , int j , vector<vector<char>>& board, string word ){

        if(idx == word.size()) return true;
        int n = board.size();
        int m = board[0].size();

        if( i<0 || j< 0 || i>=n || j>=m || word[idx] != board[i][j] ) return false;
        char temp = board[i][j];
        board[i][j] = '%';

        bool found =  dfs(idx+1,i+1,j,board,word) ||
                      dfs(idx+1,i-1,j,board,word) ||
                      dfs(idx+1,i,j+1,board,word) ||
                      dfs(idx+1,i,j-1,board,word) ;

        board[i][j] = temp;
        return found;
    }
};