/*
a move consists of either replacing one occurrence of "XL" with "LX", 
or replacing one occurrence of "RX" with "XR"

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Hint: Think of the L and R's as people on a horizontal line, where X is a space. 
The people can't cross each other, and also you can't go from XRX to RXX.
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        vector<int> startR, startL, endR, endL;
        for(int i = 0; i < start.length(); ++i){
            if(start[i] == 'R')
                startR.push_back(i);
            else if(start[i] == 'L')
                startL.push_back(i);
        }
        for(int i = 0; i < end.length(); ++i){
            if(end[i] == 'R')
                endR.push_back(i);
            if(end[i] == 'L')
                endL.push_back(i);
        }
        if((startR.size() != endR.size()) || (startL.size() != endL.size())) return false;
        start.erase(remove_if(start.begin(), start.end(), [](unsigned char x){ return x == 'X';}), start.end());
        end.erase(remove_if(end.begin(), end.end(), [](unsigned char x){ return x == 'X';}), end.end());
        if(start != end) return false;
        for(int i = 0; i < startR.size(); ++i){
            if(startR[i] > endR[i]) return false;
        }
        for(int i = 0; i < startL.size(); ++i){
            if(startL[i] < endL[i]) return false;
        }
        return true;
    }
};