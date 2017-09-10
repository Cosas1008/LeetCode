// not accepted because of Memory Limit Exceeded !!!
// dynamic programming issue of stack of memory

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > 0){
            size_t  index = t.find(s[0]);
            if(index !=std::string::npos)
            {
                string s_return = s.substr(1, s.length());
                string t_return = t.substr(index+1, t.length());
                return isSubsequence(s_return, t_return);
            }
            else
            {
                return false;
            }
        }else{
            return true;
        }
    }
};

/*
The longest common subsequence problem and Longest common substring problem are sometimes important 
for analyzing strings [analyzing genes sequence, for example]. And they can be solved efficiently using
dynamic programming. [from stackoverflow]
*/

// recommanded amendment
