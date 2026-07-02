class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int idx = 0;
        int size = target.size();
        int num = 1;
        vector<string> ans;

        while (idx < size)
        {

            while (num < target[idx])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                num++;
            }
            ans.push_back("Push");
            num++;
            idx++;
        }

        return ans;
    }
};