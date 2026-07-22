class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int freq = 0;

        int l = 0 , r = 0;
        long long sum = 0;
        int maxi = 0;

        while(r<n){
            maxi = max(maxi,nums[r]);
            sum+=nums[r];
            long long diff = (long long)maxi*(r-l+1) - sum;
            
            while( diff > k ){
                sum-=nums[l];
                l++;
                diff = (long long)maxi*(r-l+1) - sum;
            }

            freq = max( freq , r-l+1 );
            r++;
        }

        return freq;


    }
};