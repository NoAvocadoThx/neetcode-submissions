class ListNode{
public:

ListNode* prev;
ListNode* next;
int key;
int val;
ListNode()
{ 
    key = 0; 
    val = 0;
    next = nullptr;
    prev = nullptr;
}
ListNode(int k, int v) : key(k), val(v),next(nullptr), prev(nullptr) {}

   
};


class LRUCache {
public:
    unordered_map<int, ListNode*> map;
    int cap = 0;
    ListNode* left;
    ListNode* right;

    LRUCache(int capacity) {
       cap = capacity;
        map.clear();
        left = new ListNode(0, 0);
        right = new ListNode(0, 0);
       left->next  = right;
       right->prev = left;
    }

    void remove(ListNode* node)
    {
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(ListNode* node)
    {
        ListNode* prevNode = right->prev;
        node->next = right;
        node->prev = prevNode;
        prevNode->next = node;
        right->prev = node;
    }
    
    int get(int key) {
        if(map.find(key) != map.end())
        {
            ListNode* node = map[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            remove(map[key]);
        }
        ListNode* newNode = new ListNode(key, value);
        map[key] = newNode;
        insert(newNode);
        if(map.size() > cap)
        {
            ListNode* lru  = left->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
    }
};


