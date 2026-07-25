class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int notpick = dp[i-1];
            int pick = INT_MIN;
            if(i>1){
                pick = nums[i] + dp[i-2];
            }
            dp[i] = max(pick, notpick);
        }

        return dp[n-1];
    }

    int rec(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[0];
        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + rec(i - 2, nums, dp);
        int notpick = rec(i - 1, nums, dp);
        return dp[i] = max(pick, notpick);
    }
};