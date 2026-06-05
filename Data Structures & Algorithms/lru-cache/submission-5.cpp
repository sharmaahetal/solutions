class Node{
public:
    Node* prev;
    Node* next;
    int key;
    int value;

    Node(int k , int v){
        key = k;
        value = v;
        prev = next = nullptr;
    }
};
class LRUCache {
private:
    int cap;
    unordered_map<int , Node*> mp;
    Node* right;
    Node* left;

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->next = right;
        node->prev = prev;
        right->prev = node;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        nxt->prev = prev;
        prev->next = nxt;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        Node * newNode =  new Node(key , value);
        mp[key] = newNode;
        insert(newNode);

        if(mp.size() > cap){
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
