class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int res = 0;

        for(auto num:nums){
            freq[num]++;
        }
        for(auto it = freq.begin();it != freq.end();++it){
            int count = it->second;
            /* all numbers are the combination of 3 and 2 except 1*/
            if(count == 1)return -1;
            res += ceil((double)count/3);
        }
        return res;
    }
};