/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| <  |b - x|, or
|a - x| == |b - x| and a < b
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-k;
        while(r > l){
            int mid = l + (r-l)/2;
            if(x - arr[mid] > arr[mid + k] - x){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};