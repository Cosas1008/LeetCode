/*
1 <= N <= 10^9
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == queries[i].length == 2
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int N, vector< vector<int> >& lamps, vector< vector<int> >& queries) {
        // create and initialize N by N array
        unordered_map<int, int> x,y,a_d, d_d;   // post_fix _d : diagonal
        unordered_map<int, unordered_set<int> > location;               // record lamp location
        vector<int> ans;
        for(auto lamp : lamps){
            auto la_i = lamp[0], la_j = lamp[1];
            ++x[la_i];         // 0 ~ N-1
            ++y[la_j];         // 0 ~ N-1
            ++a_d[la_i+la_j];     // 0 ~ 2(N-1)
            ++d_d[N+la_i-la_j-1]; // 0 ~ 2(N-1)
            location[la_i].insert(la_j);
        }
        // queries
        for(auto query : queries){
            int light = 0;
            auto q_i = query[0], q_j = query[1];
            if(x[q_i] || y[q_j] || a_d[q_i+q_j] || d_d[q_i-q_j+N-1])
                light = 1;
            // turn off light
            for (auto li = q_i - 1; li <= q_i + 1; ++li) {
                for (auto lj = q_j - 1; lj <= q_j + 1; ++lj) {
                    if(location[li].erase(lj)) {
                        --x[li], --y[lj], --a_d[li + lj], --d_d[N + li - lj - 1];
                    }
                }
            }
            // push_back result
            ans.push_back(light);
        }
        return ans;
    }
};

int main(void)
{
    Solution s;
    int N = 5;
    vector<vector<int>> lamps_in{{0,0},{4,4}};
    vector<vector<int>> queries_in{{1,1},{1,0}};
    vector<int> result;
    result = s.gridIllumination(N, lamps_in, queries_in);
    cout << "Answer is: " << endl;
    for(auto re : result){
        cout << re << " ";
    }
    cout << endl;
    return 0;
}