class Solution {
public:
    string numberToWords(int num) {
        // every 3 number to English + unit
        string str = "";
        int thou = 0;
        vector<string> stq;
        if(num == 0) return "Zero";
        while(num > 0){
            string tmp = "";
            int grand, hund;
            grand = num % 1000;
            hund  = grand / 100;

            // Use hundred
            if(hund > 0){
                tmp += number[hund] + " Hundred ";
            }
            grand %= 100;

            if(grand > 0 && grand <= 20){ // Teens
                tmp += number[grand] + " ";
            }else{
                tmp += tens[grand / 10] + " ";
                if(grand % 10 != 0){
                    tmp += number[grand % 10] + " ";
                }
            }
            num /= 1000;
            tmp.erase(tmp.size() - 1); // remove blank at the end
            stq.push_back(tmp);
        }
        for(int i = stq.size() - 1; i>= 0; i--){
            string tmp = stq[i];
            if(tmp == "") continue;
            str += tmp;
            if(tmp[tmp.size() - 1] != ' ') str += " ";
            str += unit[i] + " ";
        }
        size_t end = str.find_last_not_of(" ");
        return (end == std::string::npos) ? "" : str.substr(0, end + 1);
    }
private:
    string unit[5]    = { "", "Thousand", "Million", "Billion", "Trillion"};
    string number[21] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    string tens[10]   = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};