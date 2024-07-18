//O(n),O(n)
/* How many rows does the vector have will decided by the number with the highest frequency*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>ele_freq;
        vector<vector<int>> res;
        for(int i = 0;i < nums.size();++i){
            ele_freq[nums[i]]++;
        }
        for(auto it = ele_freq.begin();it != ele_freq.end();++it){
            if(res.size() < it->second)res.resize(it->second);
            for(int i = 0 ; i < it->second ; i++){//put in each row
                res[i].push_back(it->first);
            }
        }
        return res;
    }
};
// class Solution {
// public:
//     // Function that rearranges numbers into a sorted matrix based on their frequency
//     std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
//         std::vector<std::vector<int>> matrix; // Will hold the final sorted matrix
//         int n = nums.size();
//         std::vector<int> count(n + 1, 0); // Initialize counting vector with zeros

//         // Count how many times each number appears in the input vector
//         for (int num : nums) {
//             ++count[num];
//         }

//         // Iterate through each unique number in the input array
//         for (int num = 1; num <= n; ++num) {
//             int frequency = count[num]; // Get the frequency of the current number

//             // Construct rows of the matrix based on the frequency of the current number
//             for (int j = 0; j < frequency; ++j) {
//                 // If there are not enough rows in the matrix, add a new row
//                 if (matrix.size() <= j) {
//                     matrix.push_back(std::vector<int>());
//                 }
//                 // Add the current number to the j-th row
//                 matrix[j].push_back(num);
//             }
//         }
      
//         // Return the organized matrix
//         return matrix;
//     }
// };
