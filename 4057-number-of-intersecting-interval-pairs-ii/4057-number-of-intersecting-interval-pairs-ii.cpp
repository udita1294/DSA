class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>h;
        long long count =0;
        for(auto &i:intervals){
            int first = i[0];
            int last = i[1];
            while(!h.empty() && h.top()<first) h.pop();
            count += h.size();
            h.push(last);
        }
        return count;
    }
};