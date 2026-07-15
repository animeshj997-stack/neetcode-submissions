class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key_, int val_){
        key=key_;
        val=val_;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int cap;

    void remove(Node* node){
        Node* nextt = node-> next;
        Node* prevv = node->prev;
        nextt->prev=prevv;
        prevv->next=nextt;
    };

    void insert(Node* node){
        Node *nextt = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextt;
        nextt->prev = node;
    };

    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node=mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->val=value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key,value);
        mp[key]=node;
        insert(node);
        if(cap<mp.size()){
            Node* nodee = tail->prev;
            int keyy = nodee->key;
            mp.erase(keyy);
            remove(nodee);
        }
    }
};
