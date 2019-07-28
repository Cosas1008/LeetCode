#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    	int reverse(int x) {
	        int number = x, rev_int = 0, previous = 0;
	        bool isNegative = false;
	        if(x < 0){
	        	number = -x;
	        	isNegative = true;
	        }

	        //reverse the positive number;
	        while(number > 0 ){
	        	int current_digit = number%10;
	        	rev_int = rev_int * 10 + current_digit;


	        	// check overflow
	        	if((rev_int - current_digit) / 10 != previous){
	        		return 0;
	        	}
	            
	            previous = rev_int;
	            number = number / 10;
	        }       

	        return (isNegative == true) ? -rev_int : rev_int;
    	}
};


int main()
{
	Solution s;
	int number = 0;
	cout << "Please Enter the number you want to reverse: " << endl;
	cin >> number;	
	cout << s.reverse(number) << endl;
	return 0;
}