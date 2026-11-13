struct Node
{
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr){}
};

class LRUCache {
public:
    Node* left;
    Node* right;
    unordered_map<int, Node*> cache;

    int cap;

    LRUCache(int capacity) {
        left = new Node(0,0);
        right = new Node(0,0);
        cache.clear();
        cap = capacity;
        left->next = right;
        right->prev = left;

    }

    ~LRUCache()
    {
        Node* cur = left;

        while(cur)
        {
            Node* tmp  = cur;
            cur = cur->next;
            delete tmp;
            tmp = nullptr;
        }
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            cache[key]->value = value;
            return;
        }

        Node* node = new Node(key, value);

        cache[key] = node;
        insert(node);
        if(cache.size() > cap)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
            lru = nullptr;
        }
    }

    void insert(Node* node)
    {
        Node* rightPrev = right->prev;
        node->next = right;
        node->prev = rightPrev;
        rightPrev->next = node;
        right->prev = node;
    }

    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;

    }
};
