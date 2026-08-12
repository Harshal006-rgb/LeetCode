class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        if( n <= 8 ) return n;
        
        if( n >= 24 ){
            ans += 8 + 16 + 24;
            int rem = n%8;
            ans += rem*4;
        }
        else if( n >= 16 ){
            ans += 8 + 16;
            int rem = n%8;
            ans += rem*3;
        }
        else{
            ans +=8;
            int rem = n%8;
            ans += rem*2;
        }
        return ans;
    }
};