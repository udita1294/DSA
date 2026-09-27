class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int x : nums)
            freq[x]++;

        vector<int> ans;
        while (ans.size() < nums.size()) {
            for (int x = 1; x <= 100; x++) {
                if (freq[x] > 0) {
                    ans.push_back(x);
                    freq[x]--;
                }
            }
        }
        return ans;
    }
};