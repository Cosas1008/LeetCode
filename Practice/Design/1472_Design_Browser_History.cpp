/*
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        cur++;
        his.resize(cur);
        his.push_back(url);
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return his[cur];
    }
    
    string forward(int steps) {
        cur = min((int) his.size() - 1, cur + steps);
        return his[cur];
    }
private:
    vector<string> his;
    int cur;
};


// Stack
stack<string> h_back, h_forward;
string cur;
BrowserHistory(string homepage) { cur = homepage; }
void visit(string url) {
    h_forward = stack<string>();
    h_back.push(cur);
    cur = url;
}
string back(int steps) {
    while (--steps >= 0 && !h_back.empty()) {
        h_forward.push(cur);
        cur = h_back.top();
        h_back.pop();
    }
    return cur;
}
string forward(int steps) {
    while (--steps >= 0 && !h_forward.empty()) {
        h_back.push(cur);
        cur = h_forward.top();
        h_forward.pop();
    }
    return cur;
}