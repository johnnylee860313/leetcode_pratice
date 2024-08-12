//O(n)
//O(1)

/*The answer will be the leftmost common part*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        while(left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }

        return left<<count;
    }
};