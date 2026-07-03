class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for( int num : nums){
            if(num%2==0) ans.push_back(num);        
        }
        for( int num : nums){
            if(num%2) ans.push_back(num);        
        }
        return ans;
    }
};