// Well, I can do it with vector
class CustomStack {
public:
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        st.push_back(x);
        if(st.size() > limit)
            st.pop_back();
    }
    
    int pop() {
        int ret = -1;
        if(st.size()){
            ret = st.back();
            st.pop_back();
        }
        return ret;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)st.size()); ++i)
            st[i] += val;
    }
private:
    vector<int> st;
    int limit;
};
class CustomStack {
public:
    // Other version
    vector<int> stack, inc;
    // inc means stack[0] ~ stack[i]
    int limit;
    CustomStack(int maxSize){
        limit = maxSize;
    }

    void push(int x){
        if(stack.size() == limit) return;
        stack.push_back(x);
        inc.push_back(0);
    }

    int pop(){
        int i = stack.size() - 1;
        if(i < 0) return;
        if(i > 0) inc[i-1] += inc[i];
        int res = stack[i] + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val){
        int i = min(k, (int)stack.size()) - 1;
        if(i >= 0) inc[i] += val; // cool
    }
};