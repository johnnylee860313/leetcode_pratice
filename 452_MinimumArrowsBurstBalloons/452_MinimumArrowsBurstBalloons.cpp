//O(n)
//O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(),points.end());

        int res = 1;
        int prev_end = points[0][1];

        for(int i = 1; i < points.size();++i){
            if(points[i][0] <= prev_end){
                prev_end = prev_end < points[i][1]?prev_end:points[i][1];
            }else{
                res++;
                prev_end = points[i][1];
            }
        }
        return res;
    }
};