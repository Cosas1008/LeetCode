class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        
    }
    
    void visit(string url) {
        if(cur < his.size()){
            his[++cur] = url;
            his.erase(his.begin() + cur, his.begin() + his.size());
        }else{
            his.push_back(url);
        }
    }
    
    string back(int steps) {
        if(steps > his.size()){
            cur = 0;
        }else{
            cur -= steps;
        }
        return his[cur];
    }
    
    string forward(int steps) {
        if(steps + cur < his.size()){
            cur += steps;
        }else{
            cur = his.size()-1;
        }
        return his[cur];
    }
private:
    vector<string> his;
    int cur = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */