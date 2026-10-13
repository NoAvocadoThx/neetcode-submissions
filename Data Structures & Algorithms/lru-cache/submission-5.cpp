struct Node
{
    Node* prev;
    Node* next;
    int val;
    int k;

    Node(int key, int value) : k(key), val(value), prev(nullptr), next (nullptr) {}
};


class LRUCache {
public:
int cap=0;
Node* left;
Node* right;
unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right =  new Node(0,0);
        left->next = right;
        right->prev= left;
    }

    ~LRUCache()
    {
        Node* node = left;
        while(node)
        {
            Node* next = node->next;
            delete node;
            next = nullptr;
            node = next;
        }
    }

    void insert(Node* node)
    {
        Node* rightMost = right->prev;
        rightMost->next = node;
        node->prev = rightMost;
        right->prev = node;
        node->next = right;
    }

    void remove(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode ->next = nextNode;
        nextNode->prev = prevNode;
        node->prev = nullptr;
        node->next = nullptr;
    
    }

    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;
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
