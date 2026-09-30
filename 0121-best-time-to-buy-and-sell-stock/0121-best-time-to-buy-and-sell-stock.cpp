class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,prices[i]);
            int diff = prices[i] - mini;
            maxi = max(maxi,diff);
        }
        return maxi;
    }
};