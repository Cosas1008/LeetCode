#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
template <typename T> void printVector(const vector<T> &integers){
    typename vector<T>::const_iterator constIterator;
    for(constIterator = integers.begin(); constIterator != integers.end(); ++constIterator)
        cout << *constIterator << " ";
}

class Solution {
public:

    int findComplement(int num) {
        vector<int> v;
        bool flag = false;
        if(num == 0){			//is not good enough
            v.push_back(0);
        }else{
            for(int i = 31; i >= 0; i--){
                unsigned int temp = pow(2.0, i);
                if(num >= temp && flag == false){
                    num -= temp;
                    v.push_back(1);
                    flag = true;
                }else if (num > temp && flag == true){
                    num -= temp;
                    v.push_back(1);
                }else if (num <= temp && flag == true) {
                    if(temp == num){
                        num = 0;
                        v.push_back(1);
                    }else{
                        v.push_back(0);
                    }
                }
            }
        }

        // there are two ways of printing out the vector
        ostream_iterator<int> output(cout, " ");
        cout << "Vector contains: ";
        copy(v.begin(), v.end() , output);
        cout << endl;
        cout << "print Vector output is : " << endl;

        //second way using const_iterator
        printVector(v);		//call printVector function
        int temp = 0;
        for( int i = v.size() -1 ; i >= 0; i--){
            if(v.at(i) == 0)
                temp += pow(2.0,v.size() - i-1);
        }
        return temp;
    }

};


int main()
{
    int y;
    y = 5;					// any number
    Solution s;
    int result = s.findComplement(y);
    cout << "Result : " << result <<endl;
    return 0;
}