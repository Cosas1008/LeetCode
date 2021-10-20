/*
ID: yuweiic1
LANG: C++
TASK: wormhole
*/
#include<iostream>
#include<fstream>

using namespace std;

#define MAX_N 12

int X[MAX_N + 1], Y[MAX_N + 1];
int partner[MAX_N + 1];
int next_on_right[MAX_N + 1];
int N;

bool cycle_exists(void)
{
    // look into partner array
    // for(int i = 1; i <= N; i++)
    //     cout << i << ":" << partner[i] << " ";
    // cout << "\n";

    // cycle detection
    for(int start = 1; start <= N; start++){
        // does there exist a cycle starting from start
        int pos = start;
        for(int step=0; step < N; step++)
            pos = next_on_right[partner[pos]];
        if(pos != 0) return true;
    }
    return false;
}

// backtracting count all posible solutions
int solve(void)
{
    // recursion: find first unpaired wormhole
    int i, j, total = 0;

    for(i = 1; i <= N; i++)
        if(partner[i] == 0) break;

    // everyone paried?
    if(i > N) {
        if(cycle_exists()) return 1;
        else return 0;
    }

    // try pairing i with all posible other wormholes j
    for(j = i+1; j <= N; j++)
        // cout << "i" << i << " j : " << j << endl;
        if(partner[j] == 0){
            // try pairing i & j, let recursion continue to generate
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0; // undo the set
        }
    return total;
}

int main(void)
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> N;
    for(int i = 1; i <= N; i++)   fin >> X[i] >> Y[i];
    fin.close();
    
    for(int i = 1; i <= N; i++) // set next_on_right
        for(int j = 1; j <= N; j++)
            if(X[j] > X[i] && Y[i] == Y[j]) // j right of i
                if(next_on_right[i] == 0 || X[j] - X[i] < X[next_on_right[i]] - X[i])
                    next_on_right[i] = j;

    fout << solve() << "\n";
    fout.close();
    return 0;
}