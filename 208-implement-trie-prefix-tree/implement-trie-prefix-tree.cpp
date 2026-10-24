class TrieNode{
public:
    TrieNode* children[26]{};
    bool isEOW{false};

    TrieNode() = default; // sets all elements to nullptr and bools to false

    ~TrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* findNode(const string& prefix){
        TrieNode* curr=root;
        for(char ch:prefix){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr){
                return nullptr;
            }
            curr=curr->children[idx];
        }
        return curr;
    }
public:
    Trie() {
        root=new TrieNode();
    }

    ~Trie(){
        delete root;
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isEOW=true;
    }
    
    bool search(string word) {
        TrieNode* curr=findNode(word);
        return curr!=nullptr && curr->isEOW;
    }
    
    bool startsWith(string prefix) {
        return findNode(prefix)!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */