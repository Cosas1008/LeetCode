/*
Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
*/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int m[10001] = {}; // max barcode size
        int peak = 0, peak_idx, pos = 0;
        for(auto n : b){
            peak = max(peak, ++m[n]);
            peak_idx = peak == m[n]? n : peak_idx;
        }
        int cnt = 0;
        for(int i = 0; i <= 10000; i++){
            int idx = i == 0? peak_idx : i;
            while(m[idx]-- > 0){
                b[pos] = idx;
                pos = pos + 2 < b.size()? pos + 2 : 1;
                cnt++;
            }
            if(cnt == b.size()) break;
        }
        return b;
    }
};