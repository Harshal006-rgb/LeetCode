class Solution {
public:

    unordered_map<string,int> mp;

    int maxLength(vector<string>& arr) {
        mp.empty();
        int n = arr.size();
        string temp;
        int i = 0;
        return rec(i,temp,arr,n);
    }

    bool uniqueChar( string s1 , string s2 ){
        vector<int> hash(26,0);
        for( char c : s1 ){
            if( hash[c-'a'] > 0 ) return false;
            hash[c-'a']++;
        }
        for( char c : s2 ){
            if( hash[c-'a'] > 0 ) return false;
            hash[c-'a']++;
        }
        return true;
    }

    int rec( int i , string temp , vector<string> &arr, int n ){
        if( i == n ) return temp.size();

        if( mp.find(temp) != mp.end()) return mp[temp];

        int include = 0;
        int exclude = 0;

        if( uniqueChar(arr[i],temp) ){
            include = rec(i+1,temp+arr[i],arr,n);
            exclude = rec(i+1,temp,arr,n);
        }
        else{
            exclude = rec(i+1,temp,arr,n);
        }

        return mp[temp] = max(exclude,include);
    }
};