class SmallestInfiniteSet {
public:
    vector<bool> arr;
    int i = 1;

    SmallestInfiniteSet() {
        arr = vector<bool>(1001,true);
    }
    
    int popSmallest() {
        while(arr[i] != true) i++;
        arr[i] = false;
        return i;
    }
    
    void addBack(int num) {
        arr[num] = true;
        i = min(i,num);        
    }
};
