class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        auto mid = next(st.begin(), st.size() / 2);
        return (double(*mid) + *prev(mid, 1 - st.size()%2)) / 2.0; 
    }
private:
    multiset<int> st;
};