class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0, r = height.size()-1;
        int ans = 0;

        while( l < r ){
            int ok = abs(l-r)*min(height[l],height[r]);
            ans = max(ok,ans);
            if( height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
            
        }

        return ans;

        
        
    }
};