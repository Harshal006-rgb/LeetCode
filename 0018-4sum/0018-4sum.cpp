class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        
        
        for( int i = 0 ; i < n ; i++ ) {
            if(i>0 && nums[i-1] == nums[i]) continue;

            for( int j = i+1 ; j < n ; j++ ) {
                if(j>i+1 && nums[j-1] == nums[j]) continue;
                
                int l = j+1, r = n-1;
                while(l<r){
                    long long sum = (long long)(nums[i])+nums[j]+nums[l]+nums[r];
                    if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++,r--;

                        while(l<r && nums[l-1] == nums[l]) l++;
                        while(l<r && nums[r+1] == nums[r]) r--;
                    }
                    else if( sum > target ){
                        r--;
                    }
                    else l++;
                }
                
            }
        }
        return ans;
        
        
    }
};