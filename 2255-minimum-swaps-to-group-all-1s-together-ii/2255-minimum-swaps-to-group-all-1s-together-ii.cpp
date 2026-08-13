class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int onecnt = 0;
        for (int i = 0; i < n; i++) if(nums[i] == 1) onecnt++;

        int cnt = 0;
        int j = 0;
        int ans = INT_MAX;

        for (int i = 0; i < 2 * n; i++)
        {
            if (nums[i % n] == 1) cnt++;

            while (i-j+1 > onecnt)
            {
                if (nums[j%n] == 1) cnt--;
                j++;
            }

            if( i-j+1 == onecnt ) ans = min(ans, onecnt - cnt);
        }

        return ans;
    }
};