class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bfs
        stack<pair<int, int>> st;
        int m = matrix.size();
        int n = matrix[0].size();
        st.push({0,n-1});
        while(!st.empty())
        {
            pair<int, int> p = st.top();
            st.pop();
            if(p.second < 0 || p.first >= m){
                continue;
            }
            int cur = matrix[p.first][p.second];
            if(cur == target){
                return true;
            }else if(cur > target){
                st.push({p.first,p.second-1});
            }else{
                st.push({p.first+1,p.second});
            }
        }
        return false;
    }
};

// best runtime ( 20 ms ) solution on Leetcode
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        ios::sync_with_stdio(0);
        int h = 0, w = a[0].size(), x;
        while(h < a.size() && w && (x = a[h][w-1]) != target) {
            if (x > target) w--;
            else h++;
        }
        while (a.size()) a.pop_back();
        return x == target;
    }
};
// second runtime ( 80 ms )
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0) {
            if(target < matrix[i][j]) {
                j--;
            } else if(target > matrix[i][j]) {
                i++;
            } else {
                return true;
            }
        }
        
        return false;
    }
};