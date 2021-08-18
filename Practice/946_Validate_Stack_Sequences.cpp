class Solution {
public:
    // Time O(N) Space O(N)
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for(int x : pushed){
            st.push(x);
            while(st.size() && popped[i] == st.top()){
                st.pop();
                i++;
            }
        }
        return st.size() == 0;
    }
    // Time O(N) Space O(1)
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(int x : pushed){
            pushed[i++] = x;
            while(i > 0 && pushed[i-1] == popped[j]){
                i--;
                j++;
            }
        }
        return i ==0;
    }
};