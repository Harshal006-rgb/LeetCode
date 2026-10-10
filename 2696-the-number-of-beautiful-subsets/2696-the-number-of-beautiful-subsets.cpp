class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp; 
        return rec(0,n,nums,k,mp)-1;
    }

    int rec( int i , int n , vector<int>& nums , int k ,unordered_map<int,int> &mp ){
        if( i == n ) return 1;
        int num = nums[i];
        int take = 0; 
        if( !mp[num-k] && !mp[num+k] ){
            mp[num]++;
            take = rec(i+1,n,nums,k,mp);
            mp[num]--;
        }
        int nottake = rec(i+1,n,nums,k,mp);
        return take + nottake;
    }
};