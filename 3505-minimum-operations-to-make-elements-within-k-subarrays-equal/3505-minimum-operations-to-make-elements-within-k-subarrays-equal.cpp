class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void add(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
            sumLow += num;
        } else {
            high.insert(num);
            sumHigh += num;
        }

        balance();
    }

    void remove(int num) {
        auto it = low.find(num);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= num;
        } else {
            it = high.find(num);
            high.erase(it);
            sumHigh -= num;
        }

        balance();
    }

    void balance() {
        int target = (low.size() + high.size() + 1) / 2;

        while (low.size() > target) {
            auto it = prev(low.end());
            int val = *it;

            low.erase(it);
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < target && !high.empty()) {
            auto it = high.begin();
            int val = *it;

            high.erase(it);
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // Calculate cost of every window of size x.
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // DP with space optimization.
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                // Don't select a subarray ending at i.
                dp[j][i] = dp[j][i - 1];

                // Select a subarray of size x ending at i.
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
