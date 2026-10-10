class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1,-1);
        vector<bool> used(n+1,false);
        rec(0,n,result,used);
        return result;
    }

    bool rec(int i , int n , vector<int> & result ,vector<bool> &used){
        if( i == 2*n-1 ) return true;

        if( result[i] != -1 ) {
            return rec(i+1,n,result,used);
        }

        for( int j = n ; j >= 1 ; j-- ) {
            if( used[j] ) continue;

            result[i] = j;
            used[j] = true;

            if( j == 1 ) {
                if( rec(i+1,n,result,used) == true ) return true;
            }
            else{
                if( j+i < 2*n-1 && result[i+j] == -1 ){
                    result[i+j] = j;
                    if( rec(i+1,n,result,used) == true ) return true;
                    result[i+j] = -1;
                }
            }

            result[i] = -1;
            used[j] = false;
        }
        return false;
    }
};