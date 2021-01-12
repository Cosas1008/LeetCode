#include <queue>
#include <string>

// same as Leetcode-127 Word Ladder, instead this time, optimize iter to mininum
using namespace std;

class Solution{
public:
    int minMutation(string start, string end, vector<string>& bank){
        queue<pair<string, int>> geneQue;
        geneQue.push({start, 0});
        const int len = bank.size();
        vector<bool> isUsed(len, false);

        // BFS
        while(!geneQue.empty())
        {
            const string gene = geneQue.front().first;
            const int iter = geneQue.front().second;

            if(end.compare(gene) == 0){
                return iter;
            }
            
            for(int i = 0 ; i < len; i++)
            {
                if(!isUsed[i] && compare_gene(gene, bank[i]) == 1){
                    geneQue.push({bank[i], iter+1});
                    isUsed[i] = true;
                }
            }

            geneQue.pop();
        }
        return -1;
    }
    bool compare_gene(const string gene, const string bank)
    {
        int len = gene.size();
        bool diff = false;
        for(int i = 0 ; i < len; i++)
        {
            if(gene[i] != bank[i]){
                diff = true;
                break;
            }
        }
        return diff;
    }
}