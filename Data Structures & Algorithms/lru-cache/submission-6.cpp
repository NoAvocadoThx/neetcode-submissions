struct Node
{
    Node* next;
    Node* prev;
    int key;
    int value;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};


class LRUCache {
public:
    int cap;
    Node* left;
    Node* right;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right ->prev = left;
        cache.clear();
    }

    ~LRUCache()
    {
      Node* node = left;
        while (node)
        {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }
    
    void insert(Node* node)
    {
        Node* rightMost = right->prev;
        rightMost->next = node;
        node->next = right;
        right->prev = node;
        node->prev = rightMost;
    }

    void remove(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->prev = nullptr; 
        node->next = nullptr;
    }


    int get(int key) {
        if(cache.find(key) !=cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->value = value;
            return;
        }
        Node* node = new Node(key,value);
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
};
