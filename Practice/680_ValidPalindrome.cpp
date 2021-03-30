class Solution {
public:
    bool validPalindrome(string s) {
        return isValidPalindrome(s, 0, s.size() - 1, 0);
    }
    bool isValidPalindrome(string& s, int i, int j, int diff)
    {
        if(diff > 1) return false;
        while( i < j){
            if(s[i] == s[j]){
                i++; j--;
            }else{
                return isValidPalindrome(s, i+1, j, diff+1) || isValidPalindrome(s, i, j-1, diff+1);
            }
        }
        return true;
    }
};

// Better
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return isValidPalindrome(s, l+1, r) || isValidPalindrome(s, l, r-1);
            }
            l++;
            r--;
        }
        return true;
    }
    bool isValidPalindrome(string& s, int i, int j)
    {
        while( i < j){
            if(s[i] == s[j]){
                i++; j--;
            }else{
                return false;
            }
        }
        return true;
    }
};