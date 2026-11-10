class Solution {
public:
    int dp[10^5+1];
    int f(int i, int n, vector<int>&costs,vector<int>& dp){
        if(i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int cost = INT_MAX;
        int j = i+1;
        if(j <= n){
            cost = costs[j-1]+((j-i)*(j-i)) + f(j,n,costs,dp);
        }
        j = i+2;
        if(j <= n){
            cost = min(cost, (costs[j-1]+((j-i)*(j-i))) + f(j,n,costs,dp));
        }
        j = i+3;
        if(j <= n){
            cost = min(cost, (costs[j-1]+((j-i)*(j-i))) + f(j,n,costs,dp));
        }
        return dp[i] = cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return f(0,n,costs,dp);
    }
};