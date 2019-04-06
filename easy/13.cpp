class Solution {
public:
    int romanToInt(string s) {
        int total = 0 ;
        map<string,int> romanConvert;
        romanConvert["I"] = 1;
        romanConvert["V"] = 5;
        romanConvert["X"] = 10;
        romanConvert["L"] = 50;
        romanConvert["C"] = 100;
        romanConvert["D"] = 500;
        romanConvert["M"] = 1000;

        for(int i = 0; i < s.length(); i++){
            int roman = romanConvert.at(string(1,s.at(i)));
            if(i == 0){
                total += roman;
            }else{
                int romanPrevious = romanConvert.at(string(1,s.at(i-1)));
                if(roman> romanPrevious){
                    total -= 2*romanPrevious;
                    total += roman;
                }else{
                    total += roman;
                }
            }
        }
        return total;
    }
};
int main() {
    Solution s;
    s.romanToInt("DCXXI");
    return 0;
}