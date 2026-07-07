class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> mp1,mp;
        for( int i = 0 ; i < n ; i++ ) mp1[nums[i]]++;
        int cnt = mp1.size();
        int ans = 0;

        while(j<n){
            mp[nums[j]]++;
            while( mp.size() == cnt ){
                ans+= n-j;
                mp[nums[i]]--;
                if( mp[nums[i]] == 0)  mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};