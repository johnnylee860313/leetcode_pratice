//核心想法是出現第一次的話將one設為1，出現第二次就將one設為0，two設為1
//O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;

        for(auto n : nums){
            one = (one^n) & ~two;
            two = (two^n) & ~one;
        }
        return one;
    }
};