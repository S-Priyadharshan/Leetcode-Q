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

    void addNode(Node* newNode){
        Node* next=head->next;
        newNode->prev=head;
        newNode->next=next;
        head->next=newNode;
        next->prev=newNode;
    }

    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* res = cache[key];
            int val=res->val;
            cache.erase(key);
            deleteNode(res);
            addNode(res);
            cache[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            cache.erase(key);
            deleteNode(node);
        }
        if(cache.size()==cap){
            cache.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        cache[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */