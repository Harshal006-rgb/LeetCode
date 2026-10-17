#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        for( int i : nums1 ) mp[i] = 1;
        for( int i : nums2 ){
            if( mp[i] == 1 ) return i;
            mp[i] = 2;
        }

        return -1;
    }
};