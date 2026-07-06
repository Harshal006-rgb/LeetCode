
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        double ans = INT_MIN;
        for( int i = 0 ; i < k ; i++ ) {
            avg += (double)nums[i]/(double)k;
        }
        ans = max(ans,avg);

        int low = 0 , high = k;
        while(high < n){
            avg -= (double)nums[low++]/(double)k;
            avg += (double)nums[high++]/(double)k;
            ans = max(ans,avg);
        }
        return ans;
    }
};