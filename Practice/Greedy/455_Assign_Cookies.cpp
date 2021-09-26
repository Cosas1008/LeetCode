/*
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i],
 we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = s.size();
        for(int j = 0; i < g.size() && j < s.size(); j++){
            if(s[j] >= g[i]) i++;
        }
        return i;
    }
};