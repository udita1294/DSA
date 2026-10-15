class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        set<int>st;
        for(int i=0;i<n;i++){
            int j = i;
            while(j < n){
                st.clear();
                for(int k = i; k <= j;k++){
                    st.insert(nums[k]);
                }
                int dis = st.size();
                res += dis*dis;
                j++;
            }
        }
        return res;
    }
};