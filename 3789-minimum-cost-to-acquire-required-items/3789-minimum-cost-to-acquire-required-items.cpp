class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long leftamt = 0;
        if((long long)cost1 + cost2 <= costBoth){
            return 1LL*need1*cost1 + 1LL*need2*cost2;
        }
        int minNeed = min(need1,need2);

        if(need1 - minNeed > 0){
            leftamt = 1LL*(need1 - minNeed)*cost1;
        }else if(need2 - minNeed > 0){
            leftamt = 1LL*(need2 - minNeed)*cost2;
        }

        return min(1LL*max(need1,need2)*costBoth , 1LL*minNeed*costBoth + leftamt) ;
    }

};