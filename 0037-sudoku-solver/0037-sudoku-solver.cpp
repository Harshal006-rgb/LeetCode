class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        vector<pair<int,int>> index;

        for( int i = 0 ; i < 9 ; i++ ) {
            for( int j = 0 ; j < 9 ; j++ ) {
                if( board[i][j] == '.'){
                    index.push_back({i,j});
                }
                
            }
        }
        int n = index.size();
        rec(board,index,n,0);
    }

    bool rec(vector<vector<char>>& board , vector<pair<int,int>> index , int n , int idx){
        if( idx == n ) return true;
        int row = index[idx].first;
        int col = index[idx].second;

        for( int i = 1 ; i <= 9 ; i++ ) {

            if( isPossible(board,row,col,i) ){
                board[row][col] = i+'0';
                if( rec(board,index,n,idx+1) ){
                    return true;
                }
                board[row][col] = '.';
            }
            
        }
        return false; 
    }

    bool isPossible( vector<vector<char>>& board , int row , int col , int num ){

        for( int i = 0 ; i < 9 ; i++ ) {
            if( board[row][i] == num+'0') return false;
        }
        for( int i = 0 ; i < 9 ; i++ ) {
            if( board[i][col] == num+'0') return false;
        }
        int rowstart = 3*(row/3);
        int colstart = 3*(col/3);

        for( int i = rowstart ; i < rowstart+3 ; i++ ) {
            for( int j = colstart ; j < colstart+3 ; j++ ) {
                if( board[i][j] == num+'0') return false;
            }
        }
        return true;
    }
};