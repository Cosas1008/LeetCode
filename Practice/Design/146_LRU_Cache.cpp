/*
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
*/
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            use(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
private:
    int capacity;
    unordered_map<int, int> cache;
    list<int> recent;
    unordered_map<int, list<int>::iterator> pos;
    void use(int key){
        if(pos.find(key) != pos.end()){
            recent.erase(pos[key]);
        }else if(recent.size() >= capacity){
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
};