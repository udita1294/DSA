class Solution {
public:
    long long canEat(vector<int>& piles, int h, int mid){
        long long actualHours = 0;
        for(int i=0;i<piles.size();i++){
            actualHours += piles[i] / mid;
            if(piles[i] % mid != 0) actualHours++;
        }
        return actualHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(canEat(piles,h,mid) <= h){
                end = mid - 1;
            }else{
                start = mid + 1;
            } 
        }
        return start;
    }
};