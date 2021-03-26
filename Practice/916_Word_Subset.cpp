class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        vector<int> feature(26);
        for(string b: B){
            vector<int> featureB(26);
            helper(featureB, b);
            for(int i = 0; i < 26; i++){
                feature[i] = max(feature[i], featureB[i]);
            }
        }
        for(string a: A){
            vector<int> feaA(26,0);
            helper(feaA, a);
            int i = 0;
            for(; i < 26; i++){
                if(feature[i] > feaA[i]) break;
            }
            if(i == 26){
                ans.push_back(a);
            }
        }
        
        return ans;
    }
    void helper(vector<int>& feature, const string str){
        for(char c: str){
            feature[c-'a']++;
        }
    }
};