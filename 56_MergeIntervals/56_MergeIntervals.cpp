class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if(intervals.size() == 1)return intervals; 
       vector<vector<int>> res;
       sort(intervals.begin(),intervals.end(),[](const auto a,const auto b){
           return a[0] < b[0];//increasing order by the first number
       });

       int i = 0;
       while(i < intervals.size()-1){
           if(intervals[i][1] >= intervals[i+1][0]){
               intervals[i+1][0] = intervals[i][0];
               intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
           }else{
               res.push_back(intervals[i]);
           }
           i++;
       }

       res.push_back(intervals[i]);

       return res;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts, ends;
        for (int i = 0; i < n; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        } 
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)return {{intervals[0][0], intervals[0][1]}};
        
        vector<vector<int>> mergeRange;
        sort(intervals.begin(),intervals.end());
        
        for(int i = 1;i < intervals.size();++i){
            if (intervals[i][0] <= intervals[i-1][1]){
                if (intervals[i-1][1] <= intervals[i][1]){
                    intervals[i][0] = intervals[i-1][0];
                }else if (intervals[i-1][1] >= intervals[i][1]){
                    intervals[i][0] = intervals[i-1][0];
                    intervals[i][1] = intervals[i-1][1];
                }
            } else {
                mergeRange.push_back({intervals[i-1][0],intervals[i-1][1]});
            }
        }
        mergeRange.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
        return mergeRange;
    }
};