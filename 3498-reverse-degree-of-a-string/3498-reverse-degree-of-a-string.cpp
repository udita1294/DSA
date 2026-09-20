class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;
        for(int i=0;i<n;i++){
            result += (26 - (s[i] - 'a')) * (i+1);
        }
        return result;
    }
};