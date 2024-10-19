//O(N),O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swp_1 = nums.size() - 2;
        int swp_2 = nums.size() - 1;

        while(swp_1 >= 0 && nums[swp_1] >= nums[swp_1 + 1])swp_1--;

        if (swp_1 >= 0) {
            while(nums[swp_2] <= nums[swp_1])swp_2--;
            swap(nums[swp_1], nums[swp_2]);
        }

        return reverse(nums.begin() + swp_1 + 1, nums.end());
    }
};

/* e.g next lexicographically permutation
1　　2　　7　　4　　3　　1 -> swap 2,3
1   3    7   4   2    1 -> reverse 7,4,2,1
1   3    1   2   4    7
*/