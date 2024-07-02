//O(n)
// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<int> res = arr;
//         while (res.size() > k) {
//             if (x - res.front() <= res.back() - x) {
//                 res.pop_back();
//             } else {
//                 res.erase(res.begin());
//             }
//         }
//         return res;
//     }
// };