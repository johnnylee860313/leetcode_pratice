class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int leftBound = intervals[0][0];
        int rightBound = intervals[0][1];
        int count = 1;

        for(int i = 1;i < intervals.size();++i){
            if (intervals[i][0] > leftBound && intervals[i][1] > rightBound) {
                leftBound = intervals[i][0];
                ++count;
            }
            rightBound = max(rightBound, intervals[i][1]);
        }

        return count;
    }
};