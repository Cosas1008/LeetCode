/*
ID: yuweiic1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int numBeads, maxCount = 0;
    string str;
    fin >> numBeads;
    fin >> str;
    for(int i =0; i < numBeads; i++){
        int counts = 1;
        char current = str[i];
        bool changed = false;
        for(int j =1;j< numBeads; j++){
            char nextColor = str[(j + i) % numBeads];
            if(current == 'w'){
                current = nextColor;
                counts += 1;
            } else if (current == nextColor || nextColor == 'w') {
                counts += 1;
            } else if (!(changed)) {
                counts += 1;
                current = nextColor;
                changed = true;
            } else {
                break;
            }
        }
        if(counts > maxCount){
            maxCount = counts;
        }
    }

    fout << maxCount << endl;
    return 0;
}