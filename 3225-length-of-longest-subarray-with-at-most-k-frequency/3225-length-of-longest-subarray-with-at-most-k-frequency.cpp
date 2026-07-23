class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = 0 , r = 0;
        int size = 0;

        while( r<n ){
            mp[nums[r]]++;
            while( mp[nums[r]] > k ){
                mp[nums[l]]--;
                l++;
            }
            size = max(size,r-l+1);
            r++;
        }
        return size;
    }
};