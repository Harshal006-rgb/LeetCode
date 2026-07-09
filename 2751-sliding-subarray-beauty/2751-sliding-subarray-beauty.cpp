class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        for (j = 0; j < k; j++)
        {
            mp[nums[j]]++;
        }

        vector<int> ans;

        int cnt = x;
        for (int idx = -50; idx <= 0; idx++)
        {
            if (mp[idx] > 0)
                cnt -= mp[idx];
            if (cnt <= 0)
            {
                ans.push_back(idx);
                break;
            }
        }
        if (cnt>0)
            ans.push_back(0);


            
        while (j < n)
        {

            mp[nums[i]]--;
            i++;
            mp[nums[j]]++;
            j++;

            cnt = x;
            for (int idx = -50; idx <= 0; idx++)
            {
                if (mp[idx] > 0)
                    cnt -= mp[idx];
                if (cnt <= 0)
                {
                    ans.push_back(idx);
                    break;
                }
            }
            if (cnt>0)
                ans.push_back(0);
        }

        return ans;
    }
};