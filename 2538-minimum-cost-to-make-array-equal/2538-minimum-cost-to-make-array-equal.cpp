class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low = *min_element(nums.begin(), nums.end());
        long long high = *max_element(nums.begin(), nums.end());

        
        while( low < high ){
            long long mid = low + ( high - low )/2;
            if( findCost(mid,nums,cost) < findCost(mid+1,nums,cost)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return findCost(high,nums,cost);
    }

    long long findCost( long long mid , vector<int>& nums, vector<int>& cost ){
        long long totalCost = 0;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ) {
            totalCost += abs(mid-nums[i])*cost[i];
        }
        return totalCost;
    }
};