class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string temp;
        for(char &c : s){
            if(isalnum(c)){
                temp += tolower(c);
            }
        }
        int t = temp.size();
        int i = 0;
        int j = t-1;
        while(i <= j){
            if(temp[i] != temp[j]){
                return false;
            }
                i++;
                j--;
        }
        return true;
    }
};