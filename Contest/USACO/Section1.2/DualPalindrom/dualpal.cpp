/*
ID: yuweiic1
LANG: C++
TASK: dualpal
*/

#include<iostream>
#include<fstream>

using namespace std;

// Function tobase referred from Youtube
// Title: Number convertion to any base, C++

string tobase(int number, int base)
{
    string baseString = "0123456789ABCDEFGHI";
    string rstr = "";
    while(number > 0 ){
        rstr = baseString[number%base] + rstr;
        number /= base;
    }
    return rstr;
}

bool checkPalindrom(string str)
{
    int len = str.size();
    for(int i =0; i < len/2; i++){
        if(str.compare(i,1,str,len-i-1,1) != 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ifstream fin;
    ofstream fout;
    int n, s, count = 0, i = 0;
    string pal = "";
    fin.open("dualpal.in");
    fout.open("dualpal.out");
    fin >> n >> s;
    // cout << "N " << n  << " S " << s << endl; // debug
    i = s+1; // set i to "greater than s" position
    while( count < n)
    {
        int success = 0;
        for(int ba = 2; ba <= 10; ba++){
            pal  = tobase(i,ba);
            if(checkPalindrom(pal)){
                if(++success == 2) ba = 11; // break the for loop
                // cout << "ba " << ba << "Count " << count << " i " << i  << " Pal " << pal << endl; // debug
            }
        }
        if(success == 2) {
            count++;
            fout << i << endl;
        }
        i += 1;
    }
    // list n number that is palindromic in at least 2 bases
    fin.close();
    fout.close();
    return 0;
}
