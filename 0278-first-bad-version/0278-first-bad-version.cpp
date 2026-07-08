class Solution {
public:
    int firstBadVersion(int n) {

        int low = 0, high = n-1;
        while(low<=high){
            int mid = low - (low-high)/2;

            if(isBadVersion(mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
        
    }
};