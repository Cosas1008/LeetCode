/*
After merging the accounts, return the accounts in the following format: 
the first element of each account is the name, and the rest of the elements are emails in sorted order. 
The accounts themselves can be returned in any order.

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> unions;
        // parents and owners init
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts.size(); ++j){
                owners[accounts[i][j]] = accounts[i][0];
                parents[accounts[i][j]] = accounts[i][j];
            }
        }
        // parents
        for(int i = 0; i < accounts.size(); ++i){
            string p = find(accounts[i][1]);
            for(int j = 2; j < accounts[i].size(); ++j)
                parents[find(accounts[i][j])] = p;
        }
        // union find
        for(int i = 0; i < accounts.size(); ++i)
            for(int j = 1; j < accounts.size(); ++j)
                unions[find(accounts[i][j])].insert(accounts[i][j]);
        
        vector<vector<string>> ans;
        for(pair<string, set<string>> p : unions){
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owners[p.first]);
            ans.push_back(emails);
        }
        return ans;
    }
private:
    unordered_map<string, string> parents;
    unordered_map<string, string> owners;
    string find(string s){
        return parents[s] == s? s : find(parents[s]);
    }
};