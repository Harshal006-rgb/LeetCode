#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0 , j = 0;
        int common = INT_MAX;

        while( i < n && j < m ){
            if( nums1[i] == nums2[j] ){
                common = nums1[i];
                break;
            }
            else if( nums1[i] < nums2[j] ) i++;
            else j++;
        }

        return common == INT_MAX ? -1 : common; 
    }
};