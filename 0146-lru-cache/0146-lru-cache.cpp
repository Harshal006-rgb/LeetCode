class LRUCache {
public:
    class Node {
    public:
       int key;
       int val;
       Node* next;
       Node* prev;
       // Constructor
       Node(int _key,int _val){
            key = _key;
            val = _val;
       }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;


    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode( Node* newNode ){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deletNode( Node* delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delnext->prev = delprev;
        delprev->next = delnext;

    }
    
    int get(int key_) {
        if(m.find(key_) != m.end()){
            Node* resNode = m[key_];
            m.erase(key_);
            deletNode(resNode);
            addNode(resNode);
            m[key_] = resNode;
            return resNode->val;
        }
        return -1;
        
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()){
            Node* existingNode = m[key_];
            m.erase(key_);
            deletNode(existingNode);
        }
        if(m.size() == cap ){
            m.erase(tail->prev->key);
            deletNode(tail->prev);
        }
        Node* newNode = new Node(key_,value);
        addNode(newNode);
        m[key_] = newNode;
        
    }
};