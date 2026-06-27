class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        rec(1,n,k,nums,ans);
        return ans;
    }


    void rec( int start , int sum , int picks , vector<int> &nums , vector<vector<int>> &ans  ){
        if(picks == 0){
            if(sum == 0 ) ans.push_back(nums);
            return;
        }

        // as number 1 to 9 hai na
        for( int i = start ; i <= 9 ; i++ ) {
            if( i > sum ) break; 
            nums.push_back(i);
            rec(i+1,sum-i,picks-1,nums,ans);
            nums.pop_back();
            
        }
    }
};