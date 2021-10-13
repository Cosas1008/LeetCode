/*
You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
*/
class Solution {
public:
    // At most k different question
    int totalFruit(vector<int>& fruits) {
        int i = 0, ret = 0, k = 2; // 2 different
        unordered_map<int,int> m;
        for(int j = 0; j < fruits.size(); ++j){
            if(!m[fruits[j]]++) k--;
            while(k < 0){
                if(m[fruits[i]]-- == 1) k++; // remove last one
                i++;
            }
            ret = max(ret, j - i + 1);
        }
        return ret;
    }
};