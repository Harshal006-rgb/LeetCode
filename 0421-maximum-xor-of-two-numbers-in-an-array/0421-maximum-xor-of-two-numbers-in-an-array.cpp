class Node {
public:
    Node* links[2];

    Node* get( int bit ){
        return links[bit];
    }

    void put( int bit , Node* node){
        links[bit] = node;
    }

    bool containsKey( int bit ){
        return links[bit] != NULL;
    }
};


class Solution {
public:
    Node* root = new Node();

    void insert( int num ){
        Node* node = root;
        for( int i = 31 ; i >= 0 ; i-- ) {
            int bit = (num>>i)&1;
            if( !node->containsKey(bit) ){
                node->put(bit,new Node());
            }   
            node = node->get(bit);                 
        }
    }

    int getMaxXor( int num ){
        Node* node = root;
        int maxXor = 0;
        for( int i = 31 ; i >= 0 ; i-- ) {
            int bit = (num>>i)&1;
            if( node->containsKey(1-bit) ){
                maxXor |= (1<<i);
                node = node->get(1-bit);                 
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;

    }

    int findMaximumXOR(vector<int>& nums) {

        for( int num : nums ) insert(num);
        int maxResult = 0;
        for ( int num : nums ) maxResult = max( maxResult , getMaxXor(num));
        return maxResult;
        
    }
};