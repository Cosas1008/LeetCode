// Return the maximum length of a subarray with positive product.
class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int ans = 0, pos = 0, neg = 0;
        for(int& a : A){
            if(a > 0){
                pos = pos > 0? pos+1 : 1; // pos at least 1
                neg = neg > 0? neg+1 : 0; // neg at least 0
            }else if(a < 0){
                int ppos = pos;
                pos = neg > 0? neg+1 : 0; // reset pos if neg leng <= 0
                neg = ppos > 0? ppos+1 : 1; // record ppos if first neg is triggered
            }else
                pos = neg = 0;
            ans = max(pos, ans);
        }
        return ans;
    }
};