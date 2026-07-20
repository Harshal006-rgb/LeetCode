class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if( grumpy[i] == 0 ) ans+= customers[i];
            else{
                grumpy[i] = customers[i];
            }
        }

        int sum = 0;
        int l = 0 , r = 0;
        int extra = 0;

        while(r<n){
            sum += grumpy[r];
            if( r-l+1 > minutes ){
                sum -= grumpy[l];
                l++;
            }
            extra = max( extra , sum );
            r++;
        }
        return ans + extra;
    }
};