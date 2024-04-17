class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cnt(1001);
        int curr = 0;

        for(auto trip:trips){
            if(trip[0] > capacity)return false;
            cnt[trip[1]] += trip[0];
            cnt[trip[2]] -= trip[0];
        }

        for(int i = 1;i <= 1000;++i){
            curr += cnt[i];
            if(curr > capacity)return false;
        }
        return true;
    }
};
