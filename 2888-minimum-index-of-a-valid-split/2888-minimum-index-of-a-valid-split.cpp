    class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();

            int number;
            int times = 0;

            for( int i = 0 ; i < n ; i++ ) {
                if( times == 0 ){
                    times = 1;
                    number = nums[i];
                }
                else if ( number == nums[i]) times++;
                else times--;
            }

            if( times == 0 ) return -1;

            times = 0;

            for( int i = 0 ; i < n ; i++ ) {
                if( number == nums[i] ) times++;
            }

            int count = 0;

            for( int i = 0 ; i < n-1 ; i++ ) {
            
                if( number == nums[i]) count++;

                int n1 = i+1;
                int n2 = n-1-i;

                if( count*2 >n1 && (times-count)*2 >n2 ){
                    return i;
                }
            }
            return -1;
        }
    };



