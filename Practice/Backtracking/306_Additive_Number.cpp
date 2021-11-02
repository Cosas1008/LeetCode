/*
Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
            1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
1. A valid additive sequence should contain at least three numbers.
2. Additive Sequence Cannot have leading zeros
*/
class Solution {
public:
    bool isAdditiveNumber(string s) {
        // find first two number
        for(int i = 1; i <= s.length()/2; ++i){
            for(int j = 1; j <= (s.length()-i) / 2; ++j){
                if(check(s.substr(0,i), s.substr(i,j), s.substr(i+j))) return true;
            }
        }
        return false;
    }
    
    bool check(string s1, string s2, string s3){
        if(s1.length() > 1 && s1[0] == '0' || s2.size() > 1 && s2[0] == '0') return false;
        string sum = add(s1, s2);
        if(sum==s3) return true;
        if(s3.length() <= sum.length() || sum != s3.substr(0,sum.length())) return false;
        else return check(s2, sum, s3.substr(sum.length()));
    }

    string add(string a, string b){
        string res = ""; 
        int i = a.length()-1, j = b.length()-1, carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry + (i >= 0? a[i--] - '0' : 0) + (j >= 0? b[j--] - '0' : 0);
            res.push_back((sum % 10)+'0');
            carry = sum / 10;
        }
        if(carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};