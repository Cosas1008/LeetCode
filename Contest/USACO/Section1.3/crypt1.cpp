/*
ID: yuweiic1
LANG: cpp
TASK: crypt1
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin;
    ofstream fout;
    int n;
    fin.open("crypt1.in", ios::in);
    fin >> n;
    int array[n] = {0};
    for(int i = 0; i < n; i++)
        fin >> array[i];
    int answer = 0;
    // brutal force
    
    cout << endl;
    fin.close();
    return 0;
}
