class Solution {
public:
    int rev( int num ){
        int ans = 0;
        while(num){
            ans = ans*10 + num%10;
            num/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long cnt = 0;
        long long mod = 1e9 + 7;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ) {
            int diff = nums[i] - rev(nums[i]);
            mp[diff]++;
            if( mp[diff] > 1) cnt = ( cnt + mp[diff]-1 ) % mod;
        }
        return cnt;
    }
};