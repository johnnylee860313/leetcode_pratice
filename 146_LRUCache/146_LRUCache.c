class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        // if(!cache[key])return NULL;
        auto it = m.find(key);
        if(it == m.end())return -1;
        cache.splice(cache.begin(),cache,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);

        if(it != m.end()){
            // it->second->second = value;
            cache.splice(cache.begin(),cache,it->second);
            m[key]->second = value;
            return;
        }

        if(cache.size()==cap){
            auto& node = cache.back();
            m.erase(node.first);
            cache.pop_back();
        }
        
        cache.emplace_front(key,value);
        m[key] = cache.begin();
    }

private:
    list<pair<int,int>> cache;//double linked list in c++
    unordered_map<int,list<pair<int,int>>::iterator> m;// told compiler make the map iterator works the same as list
    int cap;
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */