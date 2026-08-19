class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int low = 0 , high = n-1;
        int maxi = INT_MIN;

        while(low<=high){
            maxi = max(maxi,nums[low]+nums[high]);
            low++;
            high--;
        }

        return maxi;
    }
};