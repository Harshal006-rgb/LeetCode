
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int l = 0 , r = n-1;
        unordered_map<char,int> smp,emp;

        for( int i = 0 ; i < n ; i++ ) {
            if( smp.find(s[i]) == smp.end()){
                smp[s[i]] = i;
            }
        }

        for( int i = n-1 ; i >= 0 ; i-- ) {
            if( emp.find(s[i]) == emp.end()){
                emp[s[i]] = i;
            }
        }

        int size = -1;

        for( int i = 0 ; i < n ; i++ ) {
            size = max( size , emp[s[i]] - smp[s[i]] -1 );   
        }
        
        if(size<0) return -1;
        return size;
    }
};