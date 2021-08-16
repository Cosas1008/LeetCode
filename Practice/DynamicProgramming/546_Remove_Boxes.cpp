/*
You are given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
Return the maximum points you can get.

Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
*/
// Accepted Version
class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		return dfs(boxes,0, boxes.size() - 1, 0);
	}
private:
	int cache[100][100][100] = { 0 };
	int dfs(vector<int>& boxes, int l, int r, int choiced){
        //choiced means the num of boxes user choose which is same color with boxes[l] in range [0,  l)
		if (l > r)	return 0;
		int& ret = cache[l][r][choiced];
		if (ret)return ret;
		ret = (choiced + 1) * (choiced + 1) + dfs(boxes, l + 1, r, 0);
		for (int mid = l + 1; mid <= r; mid++){
			if (boxes[mid] != boxes[l])continue;
			ret = max(ret, (dfs(boxes, l + 1, mid - 1, 0) + dfs(boxes,mid, r, choiced + 1)));
			//dfs(boxes, l + 1, mid - 1, 0) in range [l+1,mid - 1]
			//dfs(boxes,mid, r, choiced + 1) inc choiced box(boxes[l]) and in range[mid,r]
			//ㄴ>(boxes[l] == boxes[mid]) so, choiced is increased in range [0,mid)
		}
		return ret;
	}
};

// TLE version
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};
        return dfs(boxes, dp, 0, n-1, 0);
    }
    int dfs(vector<int>& boxes, int& dp[100][100][100], int l, int r, int k){
        if(l > r) return 0;
        if(dp[l][r][k] != 0) return dp[l][r][k];

        while(r>l && boxes[r] == boxes[r-1]) r--, k++;
        while(r>l && boxes[l] == boxes[r]) l++, k++;
        dp[l][r][k] = dfs(boxes, dp, l, r-1, 0) + (k+1)*(k+1);

        for(int i = l ; i < r; i++){
            if(boxes[i] == boxes[r]){
                while(r>i+1 && boxes[i+1] == boxes[r]) i++;
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, l, i, k+1) + dfs(boxes, dp, i+1, r-1, 0));
            }
        }
        return dp[l][r][k];
    }
};
// Optimize with hash (TLE)
// Case [1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1]
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        unordered_map<int,int> memo;
        return dfs(boxes, memo, n, 0, n-1, 0);
    }
    int dfs(vector<int>& boxes, unordered_map<int, int>& memo, int n, int l, int r, int k){
        if (l > r) return 0;
        int key = (l*n+r)*n+k;
        if (memo.find(key) != memo.end()) return memo[key];

        while (l < r && boxes[r] == boxes[r-1]) { r--; k++; }
        while (l < r && boxes[l] == boxes[r]) { l++; k++; }
        
        key = (l*n+r)*n+k;
        memo[key] = dfs(boxes, memo, n, l, r-1, 0) + (k+1)*(k+1);
        for (int i = l; i < r; i++){
            if (boxes[i] == boxes[r]) {
                while (i+1 < r && boxes[i+1] == boxes[r]) i++;
                memo[key] = max(memo[key], dfs(boxes, memo, n, l, i, k+1) + dfs(boxes, memo, n, i+1, r-1, 0));
            }
        }
        return memo[key];
    }
};