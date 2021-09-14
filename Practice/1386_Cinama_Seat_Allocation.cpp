/*
A cinema has n rows of seats, 
numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10
*/
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& S) {
        
        int ans = 2*n;
        unordered_map<int, char> m;
        for (auto r : S)
            if (r[1] > 1 && r[1] < 10)
                m[r[0]] |= 1<<(r[1]-2);
        for (auto seat : m){
            // from 2 ~ 5
            bool p1, p2, p3;
            p1 = !(seat.second & 0b11110000);
            // from 4 ~ 7
            p2 = !(seat.second & 0b00111100);
            // from 6 ~ 9
            p3 = !(seat.second & 0b00001111);
            
            // cout << "Row " << seat.first  << " p1 " << p1 << " p2 " << p2 << " p3 " << p3 << endl;
            if(p1 && p3)
                continue;
            else if(p1 || p2 || p3)
                ans -= 1;
            else
                ans -= 2;
        }
        return ans;
    }
};