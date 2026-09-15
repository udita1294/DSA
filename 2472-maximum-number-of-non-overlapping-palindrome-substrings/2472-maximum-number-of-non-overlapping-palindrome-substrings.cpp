class Solution {
public:
    int t[2001][2001];
    int n;
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int k,int i,int j){
        if(i >= n || j >= n) return 0;

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(isPalindrome(s,i,j)){
            int takeIt = 1 + solve(s,k,j+1,j+k);
            int grow = solve(s,k,i,j+1);
            int slide = solve(s,k,i+1,j+1);

            return t[i][j] =  max({takeIt,grow,slide});
        }
        int grow = solve(s,k,i,j+1);
        int slide = solve(s,k,i+1,j+1);

        return t[i][j] =  max(grow,slide);
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        memset(t,-1,sizeof(t));
        if(k == 1) return n;
        return solve(s,k,0,k-1);
    }
};