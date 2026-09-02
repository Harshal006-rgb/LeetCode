class Solution {
public:
    vector<int> traveldays;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(costs,days,0,n,dp);
    }

    int solve( vector<int>&cost , vector<int>& days , int i , int n , vector<int> &dp){
        if( i >= n ) return 0;
        if( dp[i] != -1 ) return dp[i];

        int cost_1 = cost[0] + solve(cost,days,i+1,n,dp);

        int j = i;
        while(  j < n  && days[j] < days[i]+7){
            j++;
        }

        int cost_7 = cost[1] + solve(cost,days,j,n,dp);

        j = i;
        while(  j < n && days[j] < days[i]+30 ){
            j++;
        }

        int cost_30 = cost[2] + solve(cost,days,j,n,dp);

        return dp[i] = min({cost_1,cost_7,cost_30});

    }
};