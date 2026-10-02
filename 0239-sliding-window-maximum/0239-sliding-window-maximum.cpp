class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>hp;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            hp.push({nums[i], i});
            if (i >= k - 1) {
                while (!hp.empty() && hp.top().second <= i - k) {
                    hp.pop();
                }
                ans.push_back(hp.top().first);
            }
        }
        return ans;
    }
};
