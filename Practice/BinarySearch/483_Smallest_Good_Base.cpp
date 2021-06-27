/*
Given an integer n represented as a string, return the smallest good base of n.

We call k >= 2 a good base of n, if all digits of n base k are 1's.
Input: n = "13"
Output: "3"
Explanation: 13 base 3 is 111.

Thought : https://leetcode.com/problems/smallest-good-base/discuss/96590/3ms-AC-C%2B%2B-long-long-int-%2B-binary-search
*/
class Solution {
public:
    typedef long long ll;
    string smallestGoodBase(string n) {
        ll target = stoll(n);
        ll x = 1;
        for(int i = 62; i > 0; i--){
            if( (x << i) < target){
                ll current = helper(target, i);
                if(current != 0)
                    return to_string(current);
            }
        }
        return to_string(target-1); // at least is target - 1
    }
private:
    ll helper(ll target, int d){
        double dt = (double) target;
        ll right = (ll) (pow(dt, 1.0/d) + 1);
        ll left = 1;
        while(left < right){
            ll mid = left+(right-left)/2;
            ll sum=1, cur=1;
            for (int i=1;i<=d;i++) {
                cur*=mid;
                sum+=cur;
            }
            if (sum==target)
                return mid;
            if (sum>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return 0;
    }
};