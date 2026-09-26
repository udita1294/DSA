class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int firstDiff = abs(source[0] - target[0]);
        int secondDiff = abs(source[1] - target[1]);

        if(firstDiff == 0 && secondDiff == 0){
            return 0;
        }
        if(firstDiff == 0 || secondDiff == 0 || firstDiff == secondDiff){
            return 1;
        }
        return 2;
    }
};