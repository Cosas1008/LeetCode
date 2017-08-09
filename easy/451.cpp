struct str
{
    str():character(),cnt(0){};
    char character;
    int cnt;
};
bool compare(struct str i, struct str j) { return i.cnt > j.cnt; }

class Solution {
public:
    string frequencySort(string s) {
        string output;
        struct str count[95];
        for(int i = 0;i < 95;i++){
            count[i].character = (char) i+32;
        }
        for(int j = 0; j < s.size(); j++){
            count[s[j] - 32].cnt++;
        }
        sort(count,count+95,compare);

        for(int i = 0; i < 95; i++){
            for(int k = 0; k < count[i].cnt;k++){
                cout << count[i].character;
                output.insert(output.end(), count[i].character);
            }
        }
        return output;
    }
};