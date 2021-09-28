class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= 0 && start < arr.size() && st.insert(start).second ){
            return arr[start] == 0 || canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
        }
        return false;   
    }
private:
    unordered_set<int> st;
};