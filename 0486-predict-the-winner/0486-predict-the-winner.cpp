class Solution {
public:
    vector<vector<int>> dp;

    bool predictTheWinner(vector<int>& nums) {
       int n = nums.size();
       dp = vector<vector<int>>(n, vector<int>(n, -1));
       int diff = solve(0,n-1,nums);
       return diff >= 0;
    }

    int solve( int i , int j , vector<int>& nums ){

        if( i > j ) return 0;
        if( i == j ) return nums[i];
        if( dp[i][j] != -1 ) return dp[i][j];

        int take_i = nums[i] - solve(i+1,j,nums);
        int take_j = nums[j] - solve(i,j-1,nums);

        return dp[i][j] = max( take_i , take_j );
    }
};