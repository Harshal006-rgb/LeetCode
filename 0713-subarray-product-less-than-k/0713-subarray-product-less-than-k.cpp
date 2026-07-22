class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int l = 0 , r = 0;
        int prd = 1;
        int cnt = 0;

        while(r<n){
            prd *= nums[r];
            while(prd >= k){
                prd /= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }

        return cnt;
    }
};