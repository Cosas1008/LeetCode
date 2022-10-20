class Solution {
public:
    string intToRoman(int num) {
        int roman[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string strr[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string str = "";
        int idx = 12;
        while(num > 0){
            while(num >= roman[idx]){
                str += strr[idx];
                num -= roman[idx];
            }
            idx--;
        }
        return str;
    }
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