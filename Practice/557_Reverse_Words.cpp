#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string resultString, word;
        while(iss >> word) {
            reverse(word.begin(),word.end());
            resultString += word +' ';
        }

        return resultString.substr(0,resultString.size()-1);
    }
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        return s;
    }
};
