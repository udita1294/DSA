class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int bs = 0;
        int best = 0;
        map<pair<int,int>,int>mp;
        for(int i=1;i < nums.size();i++){
            int a = nums[i-1];
            int b = nums[i];
            if(a == b){
                bs++;
            }else{
                if(a > b){
                    swap(a,b);
                }
                mp[{a,b}]++;
                best = max(best, mp[{a,b}]);
            }
        }
        return bs + best;
    }
};