/*
Input: num = "123456579"
Output: [123,456,579]
1. Leading zeroes are not allowed
2. f.length >= 3
3. f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
4. Use long long to prevent int addition overflow, e.g. "214748364721474836422147483641"
*/
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> fib;
        helper(S, 0, fib); // backtracking
        return fib;
    }
    bool helper(string S, int start, vector<int>& fib){
        int n = S.length();
        if(start >= n && fib.size() > 2){
            return true;
        }
        int maxSpliteSize = (S[start] == '0')? 1 : 10; // key here is to make leading 0 away
        for(int len = 1; len <= maxSpliteSize && start + len <= n; len++){
            long long num = stoll(S.substr(start, len));
            if(num > INT_MAX) return false;
            int sz = fib.size();
            if(sz >= 2 && (long long) fib[sz-1] + (long long) fib[sz-2] < num)
                return false;
            if(sz <= 1 || (long long) fib[sz-1] + (long long) fib[sz-2] == num){
                fib.push_back(num);
                if(helper(S, start + len, fib)) return true;
                fib.pop_back();
            }
        }
        return false;
    }
};