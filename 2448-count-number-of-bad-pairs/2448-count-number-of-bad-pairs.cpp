class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long n = nums.size();
        long long goodpairs = 0;

        for( int i = 0 ; i < n ; i++ ) {
            int num = nums[i] - i;
            mp[num]++;
        }

        for( auto it : mp ){
            long long ok = it.second;
            goodpairs += ok*(ok-1)/2;
        }

        long long total = n*(n-1)/2;
        return total - goodpairs;
    }
};