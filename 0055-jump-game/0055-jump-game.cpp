class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int max1 = 0;
        while( i < n && i <= max1){
            max1 = max( max1 , nums[i]+i);
            i++;
        } 

        if( max1 < n-1){
            return false;
        }       
        else{
            return true;
        }
    }
};