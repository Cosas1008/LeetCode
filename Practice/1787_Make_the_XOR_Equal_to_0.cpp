class Solution {
public:
    int minChanges(vector<int>& nums, int k){
        vector<vector<int>> cnt(k, vector<int>(1<<10));
        for(int i = 0; i < int(nums.size()); i++) ++cnt[i%k][nums[i]];
        vector<int> dp(1<<10, 20000);
        int mn = 1e9;
        int sum = 0;
        dp[0] = 0;
        for(auto a : cnt)
        {
            int total = 0;
            int mx = 0;
            vector<int> dp1(1<<10, 20000);

            // Count total and mx for each a
            for(int i = 0; i < (1<<10); i++){
                if(a[i]){
                    total += a[i];
                    mx     = max(mx, a[i]); 
                }
            }

            sum += total;
            mn   = min(mn, mx);

            for(int i = 0 ; i < (1<<10); i++){
                if(a[i]){
                    int now = total - a[i];
                    for(int j = 0; j < (1<<10); j++){
                        dp1[i^j] = min(dp1[i^j],dp[j] + now);
                    }
                }
            }
            dp = dp1;
        }
        return min(dp[0], mn + sum);
    }
};

int minChanges(vector<int>& nums, int k) {
        
    int freq[k][1025]  ;
    memset(freq,0,sizeof freq) ;
    
    for(int i=0;i<nums.size();i++)
        freq[ i%k ][nums[i]]++;
    
    int dp[k+1][1025] ;
    
    for(int i=0;i<=k;i++)
        for(int j=0;j<1025;j++)
            dp[i][j] = 1e9+5 ;

    dp[0][0] = 0 ;
    int prevMin = 0 ; // it stores the min changes done till now, to obtain any xor value
    int n = nums.size() ;
    
    for(int i=0;i<k;i++){ // iterate through each a[i]
    
        // changing a[i] to one of the values from the Set S[i]
        
        for(int j=0;j<1025;j++) // the previous xor value till (i-1)th element
            
            for(int z=i;z<n;z+=k) // convert a[i] to any value from set S[i] (nums[z])
                
                if((j^nums[z])<1025)
                    //int(ceil((n-i)*1.0/k)) : count of elements in set S[i]
                    dp[i+1][j^nums[z]] = min( dp[i+1][j^nums[z]] , dp[i][j] + int(ceil((n-i)*1.0/k))-freq[i][nums[z]] ) ;
                

        int prevMin2 = 1e9+5 ;
        
        // Change a[i] to any other value so as to get the xor value = j 
            
        for(int j=0;j<1025;j++){ 
        
            // prevMin is the min change done till i-1 elements 
            
            // we are changing a[i] to a value such that the overall xor value is now equal to j
            
            dp[i+1][j] = min( dp[i+1][j] , int(ceil((n-i)*1.0/k) + prevMin) ) ;
            
            prevMin2 = min( prevMin2 , dp[i+1][j] ) ;
            
        }
        
        prevMin = prevMin2 ; // update prevMin for next iteration
    }
    return dp[k][0] ;
}