//O(n)
//O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for(int i = 0;i < nums.size();++i){
            /* eg: [4,4,1,2,3]
                when i = 0, idx will be 3 and then num[3] will turn to -2
                when i = 1, idx is also 3, abd will find num[3] already be negative 
            */
            int idx = abs(nums[i])-1;
            if(nums[idx] < 0)res.push_back(idx+1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> res;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] != nums[nums[i] - 1]) {//將nums[i]放到正確位置i-1上
//                 swap(nums[i], nums[nums[i] - 1]);
//                 --i;
//             }
//         }
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] != i + 1) res.push_back(nums[i]);
//         }
//         return res;
//     }
// };
