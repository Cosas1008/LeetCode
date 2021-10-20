/*
ID: yuweiic1
LANG: C++
TASK: skidesign
*/
#include<iostream>
#include<fstream>

using namespace std;

int N;
int hills[1001];

int main(){
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    fin >> N;
    int ans = -1;
    for(int i = 0; i < N; i++){
        fin >> hills[i];
    }
    fin.close();

    // Brute-force
    for(int i = 0; i <= 83; i++){
        int low = i, high = i + 17, change = 0;
        for(int j = 0; j < N; j++){
            if(hills[j] < low) change += (low - hills[j]) * (low - hills[j]);
            else if (hills[j] > high) change += (hills[j] - high) * (hills[j] - high);
        }
        ans = (ans == -1)? change :  min(ans, change);
    }
    fout << ans << "\n";
    fout.close();
    return 0;
}