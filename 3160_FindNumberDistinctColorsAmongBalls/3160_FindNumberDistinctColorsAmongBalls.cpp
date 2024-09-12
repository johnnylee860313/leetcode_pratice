class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> g;//color of ball[i]
        unordered_map<int, int> cnt;//numbers of each color
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            cnt[y]++;
            if (g.count(x) && --cnt[g[x]] == 0) {
                cnt.erase(g[x]);
            }
            g[x] = y;
            ans.push_back(cnt.size());
        }
        return ans;
    }
};