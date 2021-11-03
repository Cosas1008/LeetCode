class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        
        auto it = upper_bound(begin(store[key]), end(store[key]), pair<int, string>(timestamp, ""), [](const pair<int, string>& a, const pair<int, string>& b) {
                return a.first < b.first; 
            });
            
        return it == store[key].begin() ? "" : prev(it)->second;
    }
private:
    unordered_map<string, vector<pair<int,string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */