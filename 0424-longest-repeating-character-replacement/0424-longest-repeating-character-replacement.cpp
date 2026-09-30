class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_set<char>st(s.begin(),s.end());
        int ans = 0;
        for(char c : st){
            int count =0,l=0;
            for(int r=0;r<n;r++){
                if(s[r] == c){
                    count++;
                }
                while((r-l+1) - count > k){
                if(s[l] == c){
                    count--;
                }
                l++;
            }
            ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};