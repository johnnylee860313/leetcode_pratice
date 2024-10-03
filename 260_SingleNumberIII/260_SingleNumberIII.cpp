//O(n), O(n)
/*
目標是要將只出現一次的兩個數字放進a及b中
[1,2,1,3,2,5] ->
ex :  
a  [2,2,5]
b  [1,1,3]
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        int diff_bit = 1;
        int group_a = 0;
        int group_b = 0;
        vector<int> res;

        for(auto n : nums){
            xor_all ^= n;
        }

        while(!(diff_bit & xor_all)){
            diff_bit = diff_bit << 1;
        }

        for(auto n : nums){
            if (n & diff_bit) {
                group_a ^= n;
            } else {
                group_b ^= n;
            }
        }
        res.push_back(group_a);
        res.push_back(group_b);
        return res;
    }
};