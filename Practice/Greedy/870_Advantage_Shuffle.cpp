class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // Greedy
        multiset<int> s(A.begin(), A.end());
        for(int i = 0; i < B.size(); i++){
            auto p = s.upper_bound(B[i]);
            if(p == s.end()) p = s.begin();
            A[i] = *p;
            s.erase(p);
        }
        return A;
        
    }
};