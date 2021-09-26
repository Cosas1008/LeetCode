/*
Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.
*/
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }
    NestedInteger deserialize(istringstream &in){
        int number;
        if(in >> number)
            return NestedInteger(number);
        in.clear();
        in.get();
        NestedInteger list;
        while(in.peek() != ']'){
            list.add(deserialize(in));
            if(in.peek() == ',')
                in.get();
        }
        in.get();
        return list;
    }
};