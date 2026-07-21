class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> final;
        vector<vector<int>> ans;
        int i = 0;
        while(i<n){
            vector<int> temp;
            temp.push_back(nums[i]);
            i++;
            if(abs(nums[i]-nums[i-1]) > k) return final;
            temp.push_back(nums[i]);
            i++;
            if(abs(nums[i]-nums[i-1]) > k || abs(nums[i]-nums[i-2]) > k ) return final;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            i++;
        }

        return ans;
    }
};