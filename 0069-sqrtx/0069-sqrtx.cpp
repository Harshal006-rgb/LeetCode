class Solution {
public:
    int mySqrt(int x) {
        if( x<2 ) return x;
        long long low = 0, high = x/2 ,root = -1;
        while(low <= high){
            long long mid = (low+high)/2;
            if( mid*mid <= x ){
                root = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return root;
    }
};