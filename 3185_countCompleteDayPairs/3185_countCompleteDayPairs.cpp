class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        int diff_hash[24] = {0};

        for(auto hour:hours){
            count += diff_hash[(24-hour%24)%24];
            ++diff_hash[hour%24];
        }
        return count;
    }
};