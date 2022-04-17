/*
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
*/
class Solution {
public:
    bool isOneEditDistance(string A, string B) {
      int na = A.size();
      int nb = B.size();
      if(na > nb) return isOneEditDistance(B, A);
      if(nb - na > 1) return false;
      for(int i = 0; i < na; ++i)
        if(A[i] != B[i])
          if(na == nb)
            return A.substr(i+1).compare(B.substr(i+1)) == 0; // rest must be the same
          else
            return A.substr(i).compare(B.substr(i+1)) == 0;
      return (na + 1 == nb);
    }
};