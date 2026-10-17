class Solution {
public:
    int getDigSum(int n){
        int ans = 0;
        while(n > 0){
            int ld = n % 10;
            ans += ld;
            n = n / 10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>aftersorted(nums);
        auto lambda = [this](int num1,int num2){
            int dsum1 = getDigSum(num1);
            int dsum2 = getDigSum(num2);
            if(dsum1 != dsum2){
                return dsum1 < dsum2;
            }
            return num1 < num2;
        };
        sort(aftersorted.begin(),aftersorted.end(),lambda);

        unordered_map<int,int>valToIdx;

        for(int i=0;i<n;i++){
            valToIdx[nums[i]] = i;
        }

        int swap = 0;
        for(int i=0;i<n;i++){
            int expectedVal = aftersorted[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIdx[expectedVal];
            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swap++;
        }
        return swap;
    }
};