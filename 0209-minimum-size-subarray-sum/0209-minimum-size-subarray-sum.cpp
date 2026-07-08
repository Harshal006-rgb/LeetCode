
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;

        int sum = 0;
        int size = INT_MAX;
        while( j < n )
        {
            sum += nums[j];
            while(sum >= target){
                size = min(size,j-i+1);
                sum-= nums[i];
                i++;
            }
            j++;
        }
        if( size == INT_MAX ) return 0;
        return size;
    }
};