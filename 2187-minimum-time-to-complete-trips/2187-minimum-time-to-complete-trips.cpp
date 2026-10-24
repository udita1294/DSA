class Solution {
public:
    long long tripNum(vector<int>&time,long long mid){
        long long trips = 0;
        for(int i=0;i<time.size();i++){
            trips += mid/time[i];
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long start = 1;
        long long end = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(start <= end){
            long long mid = start + (end-start)/2;
            if(tripNum(time,mid) >= totalTrips){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};