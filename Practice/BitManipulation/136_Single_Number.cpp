/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> st;
        for(int& num : nums){
            if(st.find(num) == st.end()){
                st.insert(num);
            }else{
                st.erase(num);
            }
        }
        return *st.begin();
    }
    // bit manipulation with XOR
    int singleNumber(vector<int>& A){
        int result = 0;
        for(auto a : A){
            result ^= a;
        }
        return result;
    }
};