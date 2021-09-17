/*
Note that the returned integer should fit in 32-bit integer, 
if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        // next_permutation(begin(s), end(s));
        lexicographically_permutation(s);
        auto ans = stoll(s);
        return (ans <= n || ans > INT_MAX)? -1 : ans;
    }
private:
    // Hard way
    void lexicographically_permutation(string& s){
        int n = s.length();
        int k, l;
        for(k = n-2; k >= 0; k--){
            if(s[k] < s[k+1])
                break;
        }
        if(k < 0){
            reverse(s.begin(), s.end());
        }else{
            for(l = n-1; l > k; l--){
                if(s[l] > s[k])
                    break;
            }
            swap(s[k], s[l]);
            reverse(s.begin() + k + 1, s.end());
        }
    }
};