/*
ID: yuweiic1
LANG: C++
TASK: beads
*/
// runtime used more than the allotted runtime of 1 seconds
// Test 2: RUNTIME 1.715>1 (4180 KB)
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int numBeads, maxCount = 0;
    string str;
    fin >> numBeads;
    fin >> str;
    char * cstr = new char [str.length()+1];
    strcpy(cstr,str.c_str());
    for(int i=0;i< numBeads; i++)
    {
        int counts = 1; // count bead itself
        int intRight = i, intLeft = i;
        char current = cstr[i];
        char rig = cstr[(i+1)%numBeads];
        char lef = cstr[(i+numBeads-1)%numBeads];
        bool right = false, left = false;
        do{
            intRight += 1;
            char rigadd = cstr[intRight%numBeads];
            if(rig == rigadd || rigadd == 'w'){
                right = true;
                counts += 1;
            }else{
                right = false;
            }
        }while(right);
        do{
            intLeft -= 1;
            char leftadd = cstr[(intLeft+numBeads)%numBeads];
            if(lef == leftadd || leftadd == 'w'){
                left = true;
                counts += 1;
            }else{
                left = false;
            }
        }while(left);

        if(counts > maxCount && (current == lef || current == rig)){
            maxCount = counts;
        }
    }

    fout << maxCount << endl;
    return 0;
}