class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        vector<int>res;
        while(!mp.empty()){
            vector<int>rem;
            for(auto &[value,count] : mp){
                res.push_back(value);
                count--;
                if(count == 0){
                    rem.push_back(value);
                }
            }
            for(int val : rem){
                mp.erase(val);
            }
        }
        return res;
    }
};