class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>lastSkippedLen;
        string result;
        for(char &ch : s){
            if(ch == '('){
                lastSkippedLen.push(result.size());
            }else if(ch == ')'){
                int l = lastSkippedLen.top();
                lastSkippedLen.pop();
                reverse(result.begin()+l,result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};