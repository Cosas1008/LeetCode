/*
Every valid email consists of a local name and a domain name, separated by the '@' sign. 
Besides lowercase letters, the email may contain one or more '.' or '+'.
For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> elist;
        for(string e : emails){
            string clean;
            for(char c : e){
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                clean += c;
            }
            clean += e.substr(e.find('@'));
            elist.insert(clean);
        }
        return elist.size();
    }
};