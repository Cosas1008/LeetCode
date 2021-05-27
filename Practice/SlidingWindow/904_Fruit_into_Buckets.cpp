class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int head = 0;
        int ret = 0;
        int k = 2; // two types of fruit i can chose
        unordered_map<int, int> m;
        for(int j = 0; j < tree.size(); j++){
            if(!m[tree[j]]++) k--;
            while(k < 0){
                if(!--m[tree[head]]) k++;
                head++;
            }
            ret = max(ret, j - head + 1);
        }
        return ret;
    }
};