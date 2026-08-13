struct Node {
    Node * links[26] = {NULL};
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch , Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool checkEnd(){
        return flag;
    }

    void end() {
        flag = true;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node(); 
    }

    void insert(string &word){
        Node* node = root;
        for( char ch : word ){
            if(!node->containsKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->end();
    }

    string getShortestRoot(string &word) {
        Node* node = root;
        string prefix = "";
        
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
                prefix += ch;
                if (node->flag) {
                    return prefix;
                }
            } else {
                break;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        
        for (string &word : dictionary) {
            trie.insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.getShortestRoot(word);
        }

        return result;
    }
};