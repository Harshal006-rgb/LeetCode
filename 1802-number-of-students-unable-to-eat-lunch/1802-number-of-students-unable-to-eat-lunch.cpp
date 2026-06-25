class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n  = sandwiches.size();
        int cnt0 = 0 , cnt1 = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(students[i] == 1) cnt1++;
            else cnt0++;
        }

        for( int i = 0 ; i < n ; i++ ) {
            if(sandwiches[i] == 0 && cnt0 > 0 ) cnt0--;
            else if(sandwiches[i] == 1 && cnt1 > 0 ) cnt1--;
            else return (cnt1+cnt0);
        }

        return 0;

    }
};