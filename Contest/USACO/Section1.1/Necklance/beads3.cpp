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
    int i =0, numBeads, maxCount = 0;
    string str;
    fin >> numBeads;
    fin >> str;
    do
    {
        int counts = 1; // count bead itself
        int intRight = i;
        char current = str[i];
        char rig = str[(i+1)%numBeads];
        bool right, changed = false;
        do{
            intRight += 1;
            char rigadd = str[intRight%numBeads];
            if(rig == rigadd || rigadd == 'w'){
                right = true;
                counts += 1;
                i += 1;
            }else if(!(changed)){
                counts += 1;
                rig = rigadd;
                i += 1;
                changed = true;
            }else{
                break;
            }
        }while(right);
        if(counts > maxCount && (current == rig || current == 'w')){
            maxCount = counts;
        }
    }while(i < numBeads);

    fout << maxCount << endl;
    return 0;
}