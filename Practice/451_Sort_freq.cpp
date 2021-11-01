/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
*/
class Solution {
public:
    string frequencySort(string s) {
        int ch[256] = {0};
        for(char c : s){
            ch[c]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < 256; ++i){
            if(ch[i] != 0)
                pq.emplace(ch[i], i);
        }
        string ans;
        while(pq.size()){
            auto [freq, ch] = pq.top(); pq.pop();
            for(int i = 0; i < freq; ++i)
                ans += (char)ch;
        }
        return ans;
    }
};