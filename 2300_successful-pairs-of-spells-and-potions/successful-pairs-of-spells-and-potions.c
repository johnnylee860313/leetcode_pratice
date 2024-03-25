class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);

        sort(potions.begin(),potions.end());

        for(int i = 0;i < n;++i){
            long long threshold = (success-1)/spells[i];
            auto it = upper_bound(potions.begin(),potions.end(),threshold);
            if(it == potions.end())pairs[i] = 0;
            else pairs[i] = potions.end()-it;
        }
        return pairs;
    }
};