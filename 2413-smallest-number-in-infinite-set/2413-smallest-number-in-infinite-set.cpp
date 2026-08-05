class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> st;
    int currSmallest;

    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        if(!pq.empty()){
            result = pq.top();
            pq.pop();
            st.erase(result);
        }
        else{
            result  = currSmallest;
            currSmallest+=1;
        }
        return result;
    }
    
    void addBack(int num) {   
        if( num >= currSmallest || st.find(num) != st.end() ) return;
        pq.push(num);
        st.insert(num);   
    }
};
