class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> list;
        int n = nums.size();
        rec(0,n,nums,list,arr);
        return arr;
    }

    void rec( int i , int n , vector<int> & nums ,vector<int> list , vector<vector<int>> & arr){
        if( list.size() >= 2  ) arr.push_back(list);
        if( i == n ) return ;

        unordered_set<int> st;

        for( int j = i ; j < n ; j++ ) {
            if( st.count(nums[j]) ) continue;
            if( !list.empty() && list.back() > nums[j] ) continue;
            list.push_back(nums[j]);
            st.insert(nums[j]);
            rec(j+1,n,nums,list,arr);
            list.pop_back();
        }
    } 
};