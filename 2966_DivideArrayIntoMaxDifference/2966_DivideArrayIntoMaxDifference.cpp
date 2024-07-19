// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         vector<vector<int>> ans;

//         sort(nums.begin(),nums.end());

//         for (int i = 0; i < nums.size(); i += 3) {
//             if (nums[i + 2] - nums[i] > k)
//                 return {};
//             vector<int> tmp(nums.begin()+i,nums.begin()+i+3);
//             ans.push_back(tmp);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        ranges::sort(nums);

        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k)
                return {};
            ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }

        return ans;
    }
};