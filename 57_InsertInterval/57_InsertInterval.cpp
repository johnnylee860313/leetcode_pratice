class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (int i = 0; i <= n-1; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        starts.push_back(newInterval[0]);
        ends.push_back(newInterval[1]);

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        // cout<<starts[starts.size()]<<" "<<ends[ends.size()]<<endl;

        for (int i = 0, j = 0; i < n + newInterval.size()-1; i++) {
            // cout<<starts[i]<<" "<<ends[i]<<endl;
            if (i == (n + newInterval.size() - 2) || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        }
        return res;
    }
};