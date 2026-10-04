struct ListNode
{
    ListNode* next;
    ListNode* prev;
    int k;
    int v;

    ListNode()
    {
        next = nullptr;
        prev = nullptr;
        k = 0;
        v= 0;
    }

    ListNode(int key, int value): k(key), v(value), next(nullptr), prev(nullptr){}


};

class LRUCache {
public:
    int cap;
    ListNode* left;
    ListNode* right;
    unordered_map<int, ListNode*> cache;// key and pointer to ListNode

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new ListNode(0,0);
        right = new ListNode(0,0);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache()
    {
        for(ListNode* n = left;n;)
        {
            ListNode* nx = n->next;
            delete n;
            n=nx;
        }
    }

    void insert(ListNode* node)
    {
        ListNode* rightPrev = right->prev;
        node->next = right;
        right->prev = node;
        rightPrev->next = node;
        node->prev = rightPrev;
    }

    void remove(ListNode* node)
    {
        ListNode* prev  = node->prev;
        ListNode* next  = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        prev->next = next;
        next->prev = prev;
        
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end())
        {
            ListNode* node = cache[key];
            remove(node);
            insert(node);
            return node->v;
        }
        return -1;   
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            ListNode* node = cache[key];
            node->v = value;
            remove(node);
            insert(node);
            return;
        }

        ListNode* node = new ListNode(key,value);
        cache[key] = node;
        insert(node);
        if(cache.size() > cap)
        {
            ListNode* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
        }
    }
};
