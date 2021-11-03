/*
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.length();
        for(int i = 0; i < size; ++i){
            if(!isdigit(input[i])){
                vector<int> num1 = diffWaysToCompute(input.substr(0,i));
                vector<int> num2 = diffWaysToCompute(input.substr(i+1));
                for(int& n1: num1){
                    for(int& n2 : num2){
                        if(input[i] == '+')
                            result.push_back(n1 + n2);
                        else if(input[i] == '-')
                            result.push_back(n1 - n2);
                        else if(input[i] == '*')
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        if(result.empty())
            result.push_back(stoi(input));
        return result;
    }
};