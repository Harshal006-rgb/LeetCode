class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,-1);

        int cnt = 1;

        for( int j = 1 ; j < k ; j++ ) {
            if( nums[j-1] + 1 == nums[j] ) cnt++;
            else cnt = 1;        
        }

        if( cnt == k ) ans[0] = nums[k-1];

        int i = 1;
        int j = k;

        while( j < n ){
            if( nums[j-1] + 1 == nums[j] ) cnt++;
            else cnt = 1;

            if( cnt >= k ) ans[i] = nums[j];
            i++;
            j++;
        }

        return ans;        
    }
};