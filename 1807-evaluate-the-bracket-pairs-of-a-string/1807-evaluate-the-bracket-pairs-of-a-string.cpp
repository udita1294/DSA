class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &k : knowledge){
            mp[k[0]] = k[1];
        }
        for(int i = 0;i < s.size();i++){
            string temp1 = "";
            if(s[i] == '('){
                int j = i+1;
                while(s[j] != ')'){
                    temp1 += s[j];
                    j++;
                }
                if(mp.count(temp1) == 0){
                    s.replace(i,temp1.size()+2,"?");
                }else{
                    s.replace(i,temp1.size()+2,mp[temp1]);
                }
            }
        }
        return s;
    }
};