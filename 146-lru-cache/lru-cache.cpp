class LRUCache {
    struct Node{
        int key,val;
        Node* next,*prev;
        Node(int k,int v): key{k},val{v},next{nullptr},prev{nullptr}{}
    };

    int cap;
    unordered_map<int,Node*>cache;
    Node* head=new Node(-1,-1),*tail = new Node(-1,-1);

public:
    LRUCache(int capacity):cap{capacity} {
        head->next=tail;
        tail->prev=head;
    }

    ~LRUCache(){
        Node* curr=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            delete curr;
            curr=next;
        }
    }

    void addNode(Node* newNode){
        Node* next=head->next;
        newNode->prev=head;
        newNode->next=next;
        head->next=newNode;
        next->prev=newNode;
    }

    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* res=cache[key];
            int val=res->val;
            removeNode(res);
            addNode(res);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* res=cache[key];
            res->val=value;
            removeNode(res);
            addNode(res);
            return;
        }
        if(cache.size()==cap){
            Node* lru=tail->prev;
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        cache[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */