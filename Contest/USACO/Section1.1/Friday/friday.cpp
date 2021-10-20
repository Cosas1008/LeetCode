/*
ID: yuweiic1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int yearsInterval;
    fin >> yearsInterval;

    int week[7]{0}, index =  1; // index 0: Sunday, 1: Monday, 2: Tuesday
    // 1900 Jan 1st is Monday, hence the index initial value should be 1   
    for(int year =1900; year < yearsInterval + 1900; year++){
        int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if((year % 400) == 0){
            //leap year
            month[1] += 1;
        }else if((year % 4) == 0 && (year % 100) != 0){
            //leap year
            month[1] += 1;
        }

        for(int mth = 0; mth < 12; mth++){
            index = (index + 13) % 7;
            week[index] += 1;
            int remain = month[mth] - 13;
            index = (index + remain) % 7;
        }
    }
    for(int i =0; i < 7; i++){
        if(i == 6){
            fout << week[i] << endl;
        }else{
            fout << week[i] << " ";
        }
    }

    return 0;
}