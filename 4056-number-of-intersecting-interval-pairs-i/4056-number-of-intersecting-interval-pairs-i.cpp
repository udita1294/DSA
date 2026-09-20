class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int first = max(intervals[i][0] , intervals[j][0]);
                int second = min(intervals[i][1],intervals[j][1]);
                if(first <= second)count++;
            }
            
        }
        return count;
    }
};