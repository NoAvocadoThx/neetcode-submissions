struct Node
{
    Node* next;
    Node* prev;
    int k;
    int v;
    Node(int key, int val): next(nullptr), prev(nullptr), k(key), v(val){}
};

class LRUCache {
public:
int cap = 0;
Node* right;
Node* left;
unordered_map<int, Node*> cache;
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache()
    {
        Node* l = left;
        while(l)
        {
            Node* next = l->next;
            delete l;
            l = nullptr;
            l = next;
        }
    }

    void insert(Node* node)
    {
        Node* rightMost = right->prev;
        node->next = right;
        node->prev = rightMost;
        rightMost->next = node;
        right->prev = node;
    }

    void remove(Node* node)
    {
        Node* NodePrev = node->prev;
        Node* NodeNext = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        NodePrev->next = NodeNext;
        NodeNext->prev = NodePrev;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->v = value;
            return;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if(cache.size() > cap)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
            lru = nullptr;
        }
    }
};
