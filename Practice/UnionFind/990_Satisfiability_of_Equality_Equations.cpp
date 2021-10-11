/*
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; ++i)
            party[i] = i;
        for(string e: equations)
            if(e[1] == '=')
                party[find(e[0] - 'a')] = find(e[3] - 'a');
        for(string e: equations)
            if(e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }
    int find(int x){
        if(x != party[x]) party[x] = find(party[x]);
        return party[x]; 
    }
private:
    int party[26];
};