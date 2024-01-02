class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> all;
        int total = 1 << k;//2^k

        for(int i = 0;i+k <= s.size();++i){
            all.insert(s.substr(i,k));
            // size of set equals 2 power k
            if (all.size() == total){
                return true;
            }
        }
        return false;
    }
};