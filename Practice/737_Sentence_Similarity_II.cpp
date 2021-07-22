/*
Note that the similarity relation is transitive. 
For example, if “great” and “good” are similar, and “fine” and “good” are similar, then “great” and “fine” are similar.
*/
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        // dfs the similarity
        for(auto p : pairs){
            mp[p.first].insert(p.second);
            mp[p.second].insert(p.first);
        }
        unordered_set<string> visited;
        for(int i = 0; i < words1.size(); i++){
            visited.clear(); // reset visited
            if(!dfs(words1[i], words2[i], visited)) return false;
        }
        return true;
    }
    bool dfs(string s, string d, unordered_set<string>& visited){
        if(s == d) return true;
        visited.insert(s);
        for(const string& nxt : mp[s]){
            if(visited.count(nxt)) continue;
            if(dfs(nxt,d,visited)) return true;
        }
        return false;

    }
private:
    unordered_map<string, unordered_set<string>> mp;
};

// Union Find
// Author: Huahua
// Runtime: 219 ms
//Time complexity: O(|Pairs| + |words1|)
//Space complexity: O(|Pairs|)

class UnionFindSet {
public:
    bool Union(const string& word1, const string& word2) {
        const string& p1 = Find(word1, true);
        const string& p2 = Find(word2, true);
        if (p1 == p2) return false;        
        parents_[p1] = p2;
        return true;
    }
    
    const string& Find(const string& word, bool create = false) {
        if (!parents_.count(word)) {
            if (!create) return word;
            return parents_[word] = word;
        }
        
        string w = word;
        while (w != parents_[w]) {
            parents_[w] = parents_[parents_[w]];
            w = parents_[w];
        }
        
        return parents_[w];
    }
private:
    unordered_map<string, string> parents_;
};
 
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        UnionFindSet s;
        for (const auto& pair : pairs)
            s.Union(pair.first, pair.second);
        
        for (int i = 0; i < words1.size(); ++i) 
            if (s.Find(words1[i]) != s.Find(words2[i])) return false;
        
        return true;
    }
};