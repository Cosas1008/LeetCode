/*
Input: haystack = "hello", needle = "ll"
Output: 2
*/
class Solution {
public:
    // 2-pointer optimized
    int strStr(string h, string n){
        int hl = h.length();
        int nl = n.length();
        if(nl == 0) return 0;
        int j = 0;
        for(int i = 0; i < hl; ++i){
            if(h[i] == n[j])
                j++;
            else{
                i = i - j;
                j = 0;
            }
            if(j == nl) return i - j + 1;
        }
        return -1;
    }
    // 2-pointer
    int strStr(string h, string n){
        if(n == "") return 0;
        int i = 0, j = 0;
        while(i < h.length() && j < n.length()){
            if(h[i] == n[j]){
                i++; j++;
                if(j == n.length()) return i - n.length();
            }else{
                i = i - j + 1;
                j = 0;
            }
        }
        return -1;
    }
    // Wrong
    int strStr(string h, string n) {
        if(n == "" || h == n) return 0;
        auto it = h.find(n, n.length());
        if(it != string::npos)
            return it;
        else return -1;
    }
};