class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int l =0 , r=0;
        int length = 0;
        while(r < n){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            length = max(length,r-l+1);
            r++;
        }
        return length;
    }
};