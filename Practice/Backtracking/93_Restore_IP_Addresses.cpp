/*
A valid IP address consists of exactly four integers, each integer is between 0 and 255, 
separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s, ans, 0, "", 0);
        return ans;
    }
    void dfs(string& s, vector<string>& ans, int idx, string stored, int count){
        if(count > 4) return;
        if(count == 4 && idx == s.length()){
            ans.push_back(stored);
            return;
        }
        for(int i = 1; i < 4; ++i){
            if(idx+i > s.length()) break;
            string ip = s.substr(idx, i);
            if((ip[0] == '0' && ip.length() > 1) || stoi(ip) > 255) continue;
            dfs(s, ans, idx+i, stored+ip+(count==3? "":"."), count+1);
        }
    }
};