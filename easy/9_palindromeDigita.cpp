#include <iostream>
#include <sstream>
#include <cstring>

namespace std{
    template<typename T>
    std::string to_string(const T &n){
        std::ostringstream s;
        s << n;
        return s.str();
    }
}

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int length = s.length();
        char* c =  new char[length];
        for(int i =0; i < length; i ++){
            c[i] = s[i] - '0';
        }
        for(int i =0; i < length/2; i ++){
            if(c[i] == c[length-i-1]) continue;
            return false;
        }
        return true;
    }
};
int main() {
    Solution s;
    (s.isPalindrome(1991))? cout << "true": cout << "false";
    return 0;
}