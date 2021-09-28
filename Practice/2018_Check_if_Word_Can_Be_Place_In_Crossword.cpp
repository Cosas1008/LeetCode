
// Only check horizontally and vertically
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
     bool placeWordInCrossword(vector<vector<char>>& A, string s) {
        int M = A.size();
        int N = A[0].size();
        vector<vector<char>> T(N, vector<char>(M)); // `B` is the transpose of `A`
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                T[j][i] = A[i][j];
            }
        }
        return match(A, s) || match(T, s);
    }
    bool match(vector<vector<char>>& A, string s){
        int M = A.size(), N = A[0].size();
        for(int i = 0; i < M; i++){
            int j = 0;
            while(j < N){
                while(j < N && A[i][j] == '#') ++j;
                int start = j;
                while(j < N && A[i][j] != '#') ++j;
                if(same(A[i], start, j, s)) return true;
            }
        }
        return false;
    }
    bool same(vector<char>& A, int start, int end, string& s){
        if(end - start != s.length()) return false;
        int j = 0;
        // from left to right
        while(start + j < end && (A[start + j] == ' ' || A[start + j] == s[j])) ++j;
        if(j == s.length()) return true;
        j = 0;
        // from right to left
        while(end - j  > start && (A[end - j - 1] == ' ' || A[end - j - 1] == s[j])) ++j;
        return j == s.length();
    }
};