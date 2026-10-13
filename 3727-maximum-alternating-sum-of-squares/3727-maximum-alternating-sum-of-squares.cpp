class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int>vec;
        for(int i=0;i<n;i++){
            vec.push_back(abs(nums[i]));
        }
        sort(vec.begin(),vec.end());

        for(int i=0;i<n/2;i++){
            ans -= 1LL*vec[i]*vec[i];
        }
        for(int i=n/2;i<n;i++){
            ans += 1LL*vec[i]*vec[i];
        }
        return ans;
    }
};