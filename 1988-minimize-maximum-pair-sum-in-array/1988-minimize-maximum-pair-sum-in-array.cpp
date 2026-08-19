
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int N = 100001;
        vector<int> freq(N,0);
        int l = INT_MAX;
        int r = INT_MIN;

        for( int num : nums ) {
            freq[num]++;
            if( num > r ) r = num;
            if( num < l ) l = num;
        }

        int maxi = INT_MIN;

        while( l <= r ){
            while(!freq[l] && l<=r ) l++;
            while(!freq[r] && l<=r ) r--;
            if( l > r ) break;
            maxi = max( maxi , l+r );
            freq[l]--;
            freq[r]--;
        }
        return maxi;
    }
};