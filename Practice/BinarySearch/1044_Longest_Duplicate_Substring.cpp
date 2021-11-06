/*
Input: s = "banana"
Output: "ana"
Hint: To check whether an answer of length K exists, we can use Rabin-Karp 's algorithm.
*/
class Solution {
public:
    //std::string_view does not copy the whole string 
    // std::unordered_set handles the logic of hashing and comparing std::string_view's.
    string longestDupSubstring(string s) {
        string_view longest;
        unordered_set<string_view> set;
        size_t begin = 1, end = s.length();
        while(begin <= end){ // less or equal to
            auto len = begin + (end - begin) / 2;
            bool found = false;
            for(size_t i = 0; i != s.length() + 1; i++){
                const auto [it, inserted] = set.emplace(s.data()+i, len);
                if(!inserted){
                    found = true;
                    longest = *it;
                    break;
                }
            }
            if(found)
                begin = len+1;
            else
                end   = len-1;
            set.clear();
        }
        return {longest.begin(), longest.end()};
    }
};