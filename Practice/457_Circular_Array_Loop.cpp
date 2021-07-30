/*
Return true if there is a cycle in nums, or false otherwise.
Input: nums = [2,-1,1,2,2]
Output: true
Explanation:
There is a cycle from index 0 -> 2 -> 3 -> 0 -> ...
The cycle's length is 3.
*/
class Solution {
public:
    // Fast slow pointer ( need to deal with abs(A[i]) > size value)
    bool circularArrayLoop(vector<int>& A) {
        int sz = A.size();
        for(int i = 0; i < sz; i++)
            A[i] %= (A[i] < 0)? -sz : sz;

        int slow, fast, j;
        bool loop = false;
        for(int i = 0; i < sz; i++){
            slow = fast = i;
            while(A[slow]* A[next(A,fast)] > 0 &&
                 A[slow] * A[next(A, next(A, fast))] > 0){
                slow = next(A, slow);
                fast = next(A, next(A, fast));
                if(slow == fast){
                    if(slow == next(A, slow)) break;
                    loop = true;
                    break;
                }
            }
            // loop not found, set all element along the way to 0
            j = i;
            int val = A[i];
            while (A[j] * val > 0) {
                int nxt = next(A, j);
                A[j] = 0;
                j = nxt;
            }
        }
        return loop;
    }
    int next(vector<int>& nums, int i){
        int n = nums.size();
        return (n + nums[i] + i) % n;
    }
};