/*
Given an integer array nums, you need to find one continuous subarray that 
if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.
*/
class Solution {
public:
    // Sort O(nlgn)
    int findUnsortedSubarray(vector<int>& A) {
      vector<int> target = A;
      sort(target.begin(), target.end());
      int start, end;
      start = A.size(), end = 0;
      for(int i = 0; i < A.size(); ++i){
        if(target[i] != A[i]){
          start = min(start, i);
          end = max(end, i);
        }
      }
      return end - start >= 0 ? end - start + 1 : 0;
    }
    // Brute-Force O(N^2)
    int findUnsortedSubarray(vector<int>& A){
        int l = A.size(), r = 0;
        for(int i = 0; i < A.size(); ++i){
            for(int j = i + 1; j < A.size(); ++j){
                if(A[j] < A[i]){
                    l = min(l, j);
                    r = max(r, i);
                }
            }
        }
        return r - l < 0? 0 : r - l + 1;
    }
    // Stack O(n)
    int findUnsortedSubarray(vector<int>& A){
        stack<int> st;
        int l = A.size(), r = 0;
        for(int i = 0; i < A.size(); ++i){
            while(!st.empty() && A[st.top()] > A[i])
                l = min(l, st.top()), st.pop();
            st.push(i);
        }
        st.clear();
        for(int i = A.size() - 1; i >= 0; --i){
            while(!st.empty() && A[st.top()] < A[i])
                r = max(r, st.top()), st.pop();
            st.push(i);
        }
        return r - l > 0? r - l + 1 : 0;
    }
};