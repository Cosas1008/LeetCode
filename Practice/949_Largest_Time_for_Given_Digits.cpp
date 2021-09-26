/*
Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
*/

// Concise solution
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        do if((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            return to_string(A[0]) + to_string(A[1]) + ':' + to_string(A[2]) + to_string(A[3]);
        while(prev_permutation(begin(A), end(A)));
        return "";
    }
};
// Detailed one
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
        permutate(A, 0);
        if(mtime == -1)
            return ans;
        else{
            int hour = mtime / 60;
            int minu = mtime % 60;
            if(hour < 10)
                ans += '0';
            ans += to_string(hour);
            ans += ":";
            if(minu < 10)
                ans += '0';
            ans += to_string(minu);
        }
        return ans;
    }
    void permutate(vector<int> A, int start){
        if(start == A.size()){
            build_time(A);
            return;
        }
        for(int i = start; i < A.size(); i++){
            swap(A[i], A[start]);
            permutate(A, start+1);
            swap(A[i], A[start]);
        }
    }
    void build_time(vector<int> A){
        int hour = A[0] * 10 + A[1];
        int minu  = A[2] * 10 + A[3];
        if(hour < 24 && minu < 60){
            mtime = max(mtime, hour * 60 + minu);
        }
    }
private:
    int mtime = -1;
};