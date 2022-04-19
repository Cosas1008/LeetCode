// You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.
// Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
      vector<double> dp(target+1, 0);
      dp[0] = 1.0;
      for(int i = 0; i < prob.size(); ++i)
        for(int k = min(target, i+1); k >= 0; --k)
          dp[k] = (k > 0? dp[k-1] : 0) * prob[i] + dp[k] * (1-prob[i]);
      return dp[target];
    }
};