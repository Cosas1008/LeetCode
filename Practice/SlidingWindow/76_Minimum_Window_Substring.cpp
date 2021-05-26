/*
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/
string minWindow(string s, string t){
    vector<int> map(128, 0);
    for(auto c : t){
        max[c]++;
    }
    int count = t.size();
    int begin, end;
    begin = end = 0;
    int head = 0;
    int dist = INT_MAX;
    while(end < s.size()){
        if(map[s[end++]]-- > 0) count--;
        while(counter== 0){
            if(end-begin < dist){
                dist = end - begin;
                head = begin;
            }
            if(map[s[begin++]]++ == 0) count++;
        }
    }
    return dist==INT_MAX? "" : s.substr(head, dist);
}