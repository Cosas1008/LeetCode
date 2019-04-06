#include <iostream>
#include <sstream>

using namespace std;

template <typename T> void printVector(const vector<T> &integers){
    typename vector<T>::const_iterator constIterator;
    for(constIterator = integers.begin(); constIterator != integers.end(); ++constIterator)
        cout << *constIterator << " ";
}

class Solution {
public:

    vector<string> fizzBuzz(int n) {
        string string1, string2, string3;
        string1 = "Fizz";
        string2 = "Buzz";
        string3 = string1 + string2;
        vector<string> v;
        for(int i = 1; i <= n; i++){
            if((i % 15) == 0){
                v.push_back(string3);
            }else if((i%3) == 0){
                v.push_back(string1);
            }else if((i%5) == 0){
                v.push_back(string2);
            }else{
                stringstream s;
                s << i;
                v.push_back(s.str());
            }
        }
        return v;
    }

};


int main()
{
    int y;
    y = 5;
    Solution s;
    vector<string> result = s.fizzBuzz(y);
    cout << "Result : " <<endl;
    printVector(result);
    return 0;
}