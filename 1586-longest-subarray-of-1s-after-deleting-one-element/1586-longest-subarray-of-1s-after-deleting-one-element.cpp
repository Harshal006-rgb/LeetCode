class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int idx = -1;
        int i = 0 , j = 0 , n = nums.size();
        int ans = 0;
        
        while(j<n){
            if(nums[j] == 0){
                i = idx + 1;
                idx = j;
            }
            ans = max(j-i,ans);
            j++;
        }
        return ans;
    }
};