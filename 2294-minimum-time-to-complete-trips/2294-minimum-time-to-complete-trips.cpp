class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini = *min_element(time.begin(), time.end());
        long long maxi = *max_element(time.begin(), time.end());

        long long low = mini;
        long long high = (long long)maxi*totalTrips;

        while( low <= high ){
            long long mid = low - (low - high)/2;
            if( check(mid,totalTrips,time) ){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    bool check( long long mid , int totalTrips , vector<int>& time ){
        long long trips = 0;
        for( int trip : time ){
            trips += mid/trip;
        }
        return trips >= totalTrips;
    }
};