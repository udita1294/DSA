class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(char x : s1){
            mp1[x]++;
        }
        int l=0;
        int r = n-1;
        
        while(r<m){
            mp2.clear();
            for(int i=l;i<=r;i++){
                mp2[s2[i]]++;
            }
            if(mp1 == mp2){
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
};