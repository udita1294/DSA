class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size() > n){
            return "";
        }
        unordered_map<char,int>mp;
        for(char &ch : t){
            mp[ch]++;
        }
        int reqCount = t.size();
        int i=0,j=0;
        int windowSize = INT_MAX;
        int start_i = 0;

        while(j < n){
            char c = s[j];
            if(mp[c] > 0){
                reqCount--;
            }
            mp[c]--;
            while(reqCount == 0){
                int currWindowSize = j-i+1;
                if(windowSize > currWindowSize){
                    windowSize = currWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(start_i,windowSize);
    }
};