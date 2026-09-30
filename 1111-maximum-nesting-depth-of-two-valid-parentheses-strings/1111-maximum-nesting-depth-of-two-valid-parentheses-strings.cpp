class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int depth = 0;
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                depth++;
                if(depth % 2 == 0){
                    result[i] = 0;
                }else{
                    result[i] = 1;
                }
            }else{
                result[i] = (depth % 2 == 0) ? 0 : 1;
                depth--;
            }
        }
        return result;
    }
};