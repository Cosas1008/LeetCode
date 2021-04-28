class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xora = 0, xorb = 0;
        for(auto arr : arr1){
            xora ^= arr;
        }
        for(auto arr : arr2){
            xorb ^= arr;
        }
        return xora & xorb;
    }
};