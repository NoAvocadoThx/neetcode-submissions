struct Node
{
    Node* next;
    Node* prev;
    int k;
    int val;

    Node(int key, int value): k(key), val(value), next(nullptr), prev(nullptr) {}
};


class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache; // key, node
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next =  right;
        right ->prev = left;
    }
    ~LRUCache()
    {
        while(left)
        {
            Node* cur =  left;
            left = left->next;
            delete cur;
            cur = nullptr;
        }
    }

    void insert(Node* node)
    {
        Node* rightMost  = right->prev;
        right -> prev = node;
        node->next =  right;
        rightMost->next = node;
        node->prev = rightMost;
    }

    void remove(Node* node)
    {
        Node* nodeNext = node->next;
        Node* nodePrev = node->prev;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;

    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
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
            Node* leftMost = left->next;
            remove(leftMost);
            cache.erase(leftMost ->k);
            delete leftMost;
            leftMost = nullptr;
        }
    }
};
