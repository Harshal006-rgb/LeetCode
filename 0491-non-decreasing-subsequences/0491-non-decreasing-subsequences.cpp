class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> arr;
        vector<int> list;
        int n = nums.size();
        rec(0,n,nums,list,arr);
        vector<vector<int>> ans(arr.begin(),arr.end());
        return ans;
    }

    void rec( int i , int n , vector<int> & nums ,vector<int> list , set<vector<int>> & arr){
        if( list.size() >= 2  ) arr.insert(list);
        if( i == n ) return ;
        if( list.empty() || list.back() <= nums[i] ){
            list.push_back(nums[i]);
            rec(i+1,n,nums,list,arr);
            list.pop_back();
        }
        rec(i+1,n,nums,list,arr);
    } 
};