class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        int i = 0;
        for (string& path : paths) 
        {
            istringstream iss (path); 
            string file;
            string dir;
            while (iss >> file) {                
                if(i == 0) {
                    dir = file;
                    i=1;
                } else {
                    int k = file.find("(");
                    mp[file.substr(k)].push_back(dir + "/" + file.substr(0, k)); 
                }
                
            }
            i = 0;
        }
        for(auto entity : mp){
            if(entity.second.size() > 1){
                ans.push_back(entity.second);
            }
        }
        return ans;
    }
};