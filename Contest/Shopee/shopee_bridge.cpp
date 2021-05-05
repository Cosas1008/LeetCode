#include<iostream>
#include<vector>

using namespace std;

int findMaxRoute(vector<int>& park, bool back);

int t, n, m;

int main()
{
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        cin >> n >> m;
        vector< vector<int> > park(n, vector<int>(m+1));
        for(int ni = 0; ni < n; ni++)
        {
            int sum = 0;
            for(int mi = 0 ; mi < m; mi++)
            {
                int num;
                cin >> num;
                park[ni][mi] = num;
                sum += num;
            }
            park[ni][m] = sum;
        }
        int dp[n+1][2];
        dp[0][0] = 0; // not cross
        dp[0][1] = 0; // cross
        dp[1][1] = park[0][m]; // set cross
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = min(dp[i-1][0], min(dp[i-1][1] + park[i][m], dp[i-1][0] + findMaxRoute(park[i], false)));
            if(i != 1) dp[i][1] = min(dp[i-1][1], min(dp[i-1][0] + park[i][m], dp[i-1][1] + findMaxRoute(park[i], true)));
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}

int findMaxRoute(vector<int>& park, bool back)
{
    int path = 0;
    int maxPath = INT_MIN;
    
    if(back){
        for(int i = m-1; i >= 0; i--){
            path += park[i];
            maxPath = max(maxPath, path);
        }
    }else{
        for(int i = 0; i < m; i++){
            path += park[i];
            maxPath = max(maxPath, path);
        }
    }
    return maxPath;
}