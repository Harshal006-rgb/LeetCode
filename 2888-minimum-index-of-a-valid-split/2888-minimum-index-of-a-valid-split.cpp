class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for( int num : nums ) mp1[num]++;

        for( int i = 0 ; i < n ; i++ ) {
        
            int num = nums[i];
            mp1[num]--;
            mp2[num]++;

            int n1 = i+1;
            int n2 = n-1-i;

            if( mp1[num]*2 >n2 && mp2[num]*2 >n1 ){
                return i;
            }

        }
        return -1;
    }
};