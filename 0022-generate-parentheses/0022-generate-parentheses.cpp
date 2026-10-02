class Solution {
public:
    vector<string> solve(int n,int open, int closed,vector<string>&result, string &temp){
        if(open == n && closed == n){
            result.push_back(temp);
        }
        if(open < n){
            temp.push_back('(');
            solve(n,open+1,closed,result,temp);
            temp.pop_back();
        }
        if(closed < open){
            temp.push_back(')');
            solve(n,open,closed+1,result,temp);
            temp.pop_back();
        }
        return result;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp="";
        return solve(n,0,0,result,temp);

    }
};