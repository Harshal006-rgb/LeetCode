class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        rec(0, nums, subset, res);
        return res;        
    }

    void rec(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {

        //Method-1

        res.push_back(subset);

        for( int i = idx ; i < nums.size() ; i++ ) {
            if(i>idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            rec(i+1,nums,subset,res);
            subset.pop_back();
        }
        
        // Method - 2
        // if (i == nums.size()) {
        //     res.push_back(subset);
        //     return;
        // }
        // subset.push_back(nums[i]);
        // rec(i + 1, nums, subset, res);
        // subset.pop_back();
        // while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        //     i++;
        // }
        // rec(i + 1, nums, subset, res);
    }    
};