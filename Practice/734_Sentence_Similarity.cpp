/*
For example, “great acting skills” and “fine drama talent” are similar, 
if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
*/
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, unordered_set<string>> similar_words;
        for (const auto& pair : pairs) {            
            similar_words[pair.first].insert(pair.second);
            similar_words[pair.second].insert(pair.first);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (!similar_words[words1[i]].count(words2[i])) return false;
        }
        
        return true;
    }
};