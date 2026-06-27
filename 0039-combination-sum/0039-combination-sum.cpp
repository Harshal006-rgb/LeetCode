class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> nums;
        rec(candidates,target,ans,nums,0,n);
        return ans;
    }

    void rec(vector<int>& arr,int target,vector<vector<int>> &ans , vector<int> nums , int i , int n ){
        if( i == n ){
            if( target == 0 ){
                ans.push_back(nums);
            }
            return;
        }

        rec(arr,target,ans,nums,i+1,n);

        if(target>=arr[i]){
            nums.push_back(arr[i]);
            rec(arr,target-arr[i],ans,nums,i,n);
            // nums.pop_back();
        }




    }
};
