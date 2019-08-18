class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> answer;
        string first = A.at(0);
        for(int i = 0 ; i < first.length(); i++)
        {
            // recurrsive call
            char tmp = first[i];
            // cout << "tmp " << tmp << endl;
            int isFound = 1;
            for(vector<string>::iterator it = A.begin()+1; it != A.end(); it++)
            {
                // cout << "it " << *it << endl;
                size_t pos = (*it).find(tmp);
                if(pos!=std::string::npos)
                {
                    // found
                    (*it).erase(pos,1);
                }else{
                    isFound = 0;
                    break;
                }
            }
            if(isFound){
                string s;
                s.push_back(tmp);
                answer.push_back(s);
            }
        }
        return answer;
    }
};
