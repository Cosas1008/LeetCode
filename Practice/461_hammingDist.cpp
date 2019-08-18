class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        bool xflag = false;
        bool yflag = false;
        cout << " x is " << x << endl;
        cout << " y is " << y << endl;
        for(int i = 31; i > 0; i --){
            unsigned int temp = pow(2.0,i);
            if( x >= temp){
                x -= temp;
                xflag = true;  // true == 1
            }
            if(y >= temp){
                y -= temp;
                yflag = true; //true == 1
            }
            if(xflag != yflag){
                count ++;
            }
            xflag = yflag = false; // set bit == 0
        }
        if(x != y)
            count++;
        cout << count << endl;
        return count;
    }
};