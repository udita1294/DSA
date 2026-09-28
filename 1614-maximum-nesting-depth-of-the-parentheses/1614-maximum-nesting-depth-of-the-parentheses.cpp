class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                count++;
                maxi = max(maxi,count);
            }else if(s[i] == ')'){
                count--;
            }
        }
        return maxi;
    }
};