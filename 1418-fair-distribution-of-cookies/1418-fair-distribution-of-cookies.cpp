#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int ans = INT_MAX;

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k,0);
        int n = cookies.size();
        rec(0,n,cookies,child);
        return ans;
    }

    void rec( int i , int n , vector<int>& cookies , vector<int> & child ){
        if( i == n ){
            int maxi = INT_MIN;
            for( int x : child ) maxi = max(x,maxi);
            ans = min(maxi,ans);
            return;
        }

        for( int j = 0 ; j < child.size() ; j++ ) {
            child[j] += cookies[i];
            rec(i+1,n,cookies,child);
            child[j] -= cookies[i];
            
        }
    }
};