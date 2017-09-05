#include <cmath>
#include <iostream>
#include <algorithm>
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

bool cmp(int value1, int value2){
    string int1;
    int1 = to_string(value1);
    string int2 = to_string(value2);
    string combination1 = int1 + int2;
    string combination2 = int2 + int1;
    long double comboint1 = atof(combination1.c_str());
    long double comboint2 = atof(combination2.c_str());
    if(comboint1 > comboint2){
        return true;
    }else{
        return false;
    }
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        vector<int>::iterator it;
        string s = "";
        for(it=nums.begin(); it != nums.end(); it++){
            s += to_string(*it);
        }

        return s;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(999999999);
    nums.push_back(999999997);
    nums.push_back(999999998);
    cout << s.largestNumber(nums) << endl;
	return 0;
}
