/*
    Design data structure that follows constraints of an LRU cache

    Hash map + doubly linked list, left = LRU, right = MRU
    get: update to MRU, put: update to MRU, remove LRU if full

    Time: O(1)
    Space: O(capacity)
*/

class Node {
public:
    int k;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int value) {
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            
            // Free allocated memory for the removed node
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if (cache.size() > cap) {
            // remove from list & delete LRU from map
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->k);
            
            // Free allocated memory for the removed node
            delete lru;
        }
    }
private:
    int cap;
    unordered_map<int, Node*> cache; // {key -> node}
    Node* left;
    Node* right;
    
    // remove node from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    // insert node at right
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        
        prev->next = node;
        next->prev = node;
        
        node->prev = prev;
        node->next = next;
    }
};
// class LRUCache {
// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//     }

//     int get(int key) {
//         // if(!cache[key])return NULL;
//         auto it = m.find(key);
//         if(it == m.end())return -1;
//         cache.splice(cache.begin(),cache,it->second);
//         return it->second->second;
//     }
    
//     void put(int key, int value) {
//         auto it = m.find(key);

//         if(it != m.end()){
//             // it->second->second = value;
//             cache.splice(cache.begin(),cache,it->second);
//             m[key]->second = value;
//             return;
//         }

//         if(cache.size()==cap){
//             auto& node = cache.back();
//             m.erase(node.first);
//             cache.pop_back();
//         }
        
//         cache.emplace_front(key,value);
//         m[key] = cache.begin();
//     }

// private:
//     list<pair<int,int>> cache;//double linked list in c++
//     unordered_map<int,list<pair<int,int>>::iterator> m;// told compiler make the map iterator works the same as list
//     int cap;
// };



// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
    UT_hash_handle hh; /* makes this structure hashable */
} Node;


typedef struct {
    int cap;
    Node* leftMost;     // LRU
    Node* rightMost;    // MRU
} LRUCache;

Node* hashedNodes = NULL;

void removeNode(Node* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Insert node at the right (MRU), just before the rightMost node
void insertNode(Node* node, LRUCache* cache)
{
    Node* prev = cache->rightMost->prev;
    Node* next = cache->rightMost;
    
    prev->next = node;
    next->prev = node;
    
    node->next = next;
    node->prev = prev;
}


LRUCache* lRUCacheCreate(int capacity) {
    // Allocate space for LRUCache
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    
    // Set the capacity
    cache->cap = capacity;
    
    // Allocate space for the leftMost and rightMost nodes
    cache->leftMost = (Node*)malloc(sizeof(Node));
    cache->rightMost = (Node*)malloc(sizeof(Node));
    
    // Initialize the nodes where we connect the leftMost and rightMost to form the list
    cache->leftMost->prev = NULL;
    cache->leftMost->next = cache->rightMost;
    
    cache->rightMost->prev = cache->leftMost;
    cache->rightMost->next = NULL;
    
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node;
    HASH_FIND_INT(hashedNodes, &key, node);
    
    // Check if the key exists
    if(node)
    {
        // Remove the node from its current position in the list
        removeNode(node);
        
        // Insert the node at the right (MRU)
        insertNode(node, obj);
        
        return node->value;
    }
    
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node;
    HASH_FIND_INT(hashedNodes, &key, node);
    
    // Check if the key exists
    if(node)
    {
        // Remove the node from its current position in the list
        removeNode(node);
        
        // Update the node's current value
        node->value = value;
    }
    else
    {
        // Allocate space for a new node
        node = (Node*)malloc(sizeof(Node));
        // Initialize the node
        node->key = key;
        node->value = value;
        
        // Add the new node to the hash
        HASH_ADD_INT(hashedNodes, key, node);
    }
    
    // Insert the node at the right (MRU)
    insertNode(node, obj);
    
    // Check if we have exceeded the capacity after adding the new node
    if(HASH_COUNT(hashedNodes) > obj->cap)
    {
        Node* LRUNode = obj->leftMost->next;
        
        // Remove the left node (LRU) from the list
        removeNode(LRUNode);
        
        // Remove the node from the hash
        HASH_DEL(hashedNodes, LRUNode);
        
        // Deallocate the node
        free(LRUNode);
    }
}

void lRUCacheFree(LRUCache* obj) {
    // Deallocate the nodes first
    free(obj->leftMost);
    free(obj->rightMost);
    
    // Deallocate the LRUCache
    free(obj);
    
    // Delete and deallocate all the nodes from the hash
    Node *currentNode, *tmp;

    HASH_ITER(hh, hashedNodes, currentNode, tmp) {
        HASH_DEL(hashedNodes, currentNode);  /* delete; nodes advances to next */
        free(currentNode);
   }
}
