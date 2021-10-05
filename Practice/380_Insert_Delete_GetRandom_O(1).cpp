class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(find(arr.begin(), arr.end(), val) != arr.end()) return false;
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = find(arr.begin(), arr.end(), val);
        if(it != arr.end()){
            arr.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
private:
    vector<int> arr;
};

