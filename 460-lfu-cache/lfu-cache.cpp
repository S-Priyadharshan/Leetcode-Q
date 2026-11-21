class LFUCache {
private:
    struct Node{
        int key,val,freq;
        Node* next,*prev;
        Node(int key,int val):key{key},val{val},freq{1},next{nullptr},prev{nullptr}{}
    };

    struct DLL{
        Node* head,*tail;
        int size;

        DLL():size{0}{
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
        }

        ~DLL(){
            Node* curr=head;
            while(curr){
                Node* next=curr->next;
                delete curr;
                curr=next;
            }
        }

        void addFront(Node* newNode){
            Node* next=head->next;
            newNode->next=next;
            newNode->prev=head;
            head->next=newNode;
            next->prev=newNode;
            size++;
        }

        void removeNode(Node* node){
            node->next->prev=node->prev;
            node->prev->next=node->next;
            size--;
        }
    };

    int cap,minFreq;
    unordered_map<int,Node*> keyToNode;
    unordered_map<int,DLL*> freqToList;

    DLL* getList(int freq){
        if(freqToList.find(freq)==freqToList.end()){
            freqToList[freq]=new DLL();
        }
        return freqToList[freq];
    }

    void updateFreq(Node* node){
        int oldFreq = node->freq;
        DLL* oldList = freqToList[oldFreq];
        oldList->removeNode(node);

        if(oldFreq==minFreq && oldList->size==0){
            minFreq++;
        }

        node->freq++;
        getList(node->freq)->addFront(node);
    }

public:
    LFUCache(int capacity):cap{capacity},minFreq{0} {}

    ~LFUCache(){
        for(auto& [freq,list]:freqToList){
            delete list;
        }
    }
    
    int get(int key) {
        if(cap==0 || keyToNode.find(key)==keyToNode.end()){
            return -1;
        }   
        Node* node=keyToNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap==0)return;

        if(keyToNode.find(key)!=keyToNode.end()){
            Node* node=keyToNode[key];
            node->val=value;
            updateFreq(node);
            return;
        }

        if(keyToNode.size()==cap){
            DLL* minList = freqToList[minFreq];
            Node* lfuNode = minList->tail->prev;
            keyToNode.erase(lfuNode->key);
            minList->removeNode(lfuNode);
            delete lfuNode;
        }

        Node* newNode = new Node(key,value);
        keyToNode[key]=newNode;
        minFreq=1;
        getList(1)->addFront(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */