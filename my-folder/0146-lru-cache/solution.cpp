class node {
    public:
        int val;
        int key;
        node* next, *prev;

        node(int key, int val) {
            this->val = val;
            this->key = key;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
private:
    unordered_map<int,node*> mp;
    int capacity;
    node*head = new node(-1,-1);
    node*tail = new node(-1,-1);
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node* n) {
        node* nx = n->next;
        node* pr = n->prev;

        pr->next = nx;
        nx->prev = pr;
    }

    void addNode(node* n) {
        node* temp = head->next;
        head->next = n;
        n->next = temp;
        n->prev = head;
        temp->prev = n;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        node* keyNode = mp[key];
        deleteNode(keyNode);
        addNode(keyNode);
        mp[key] = keyNode;
        return keyNode->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* keyNode = mp[key];
            keyNode->val = value;
            deleteNode(keyNode);
            addNode(keyNode);
            mp[key] = keyNode;
        } else {
            if (capacity == mp.size()) {
                node* prev = tail->prev;
                deleteNode(prev);
                node*l = new node(key,value);
                addNode(l);
                mp.erase(prev->key);
                mp[key] = l;
            } else {
                node*l = new node(key,value);
                addNode(l);
                mp[key] = l;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
