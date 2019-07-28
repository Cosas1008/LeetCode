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
};

int main() {
    string result,c = "hello you are";
    Solution s;
    result = s.reverseWords(c);
    cout << result << endl;
    return 0;
}

/*有人寫得更好*/

string reverseString(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j){
        swap(s[i++], s[j--]); 
    }
    
    return s;
}

//or
string reverseString(string s) {
    for(int i=0,j=s.length()-1; i<j; ++i,--j){}
            swap(s[i], s[j]);
    return s;
}