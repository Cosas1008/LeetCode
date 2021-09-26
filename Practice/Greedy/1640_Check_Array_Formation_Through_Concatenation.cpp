/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. 
Your goal is to form arr by concatenating the arrays in pieces in any order. 
However, you are not allowed to reorder the integers in each array pieces[i].

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        for(auto& piece : pieces){
            mp.emplace(piece[0], piece);
        }
        // greedy
        int i = 0;
        for(; i <  arr.size();){
            if(mp.count(arr[i])){
                // check every element inside
                auto tmp = mp[arr[i]];
                for(auto& t : tmp){
                    if(arr[i] != t) break;
                    i++;
                }
            }else{
                break;
            }
        }
        return i == arr.size();
    }
    // Concise way!
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> ps(101, -1);
        for (int i = 0; i < pieces.size(); ++i)
            ps[pieces[i][0]] = i;
        for (int i = 0; i < arr.size(); ) {
            int p = ps[arr[i]], j = 0;
            if (p == -1)
                return false;
            while (j < pieces[p].size())
                if (arr[i++] != pieces[p][j++])
                    return false;
        }
        return true;
    }
};