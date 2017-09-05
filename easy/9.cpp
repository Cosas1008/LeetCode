#include <iostream>
#include <sstream>


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
        char const *c = s.c_str();
        
    }
};
int main() {
    Solution s;
    (s.isPalindrome(1991))? cout << "true": cout << "false";
    return 0;
}