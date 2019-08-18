typedef pair<char, int> mycomp;
struct Compare
{
    bool operator() (const mycomp& left, const mycomp& right) const
    {
        return left.second < right.second;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0){
            return -1;
        }
        for(int i =0;i < s.size(); i++){
            char ch = s.at(i);
            if(words.find(ch) != words.end()){
                //found
    
                if(index.find(ch) != index.end()){
                    // found the index and replace it for repetitive reason
                    index[ch] = INT_MAX;
                }
    
            }else{
                // not found
                words.insert(ch);
                index[ch] = i;
            }
        }
        //find the min value, if the min is max ==> not found
    
        pair<char,int> min = *min_element(index.begin(),index.end(),Compare());
        if(min.second < INT_MAX){
            return min.second;
        }else{
            return -1;
        }
    }
private:
    set<char> words;
    map<char,int> index;    
};