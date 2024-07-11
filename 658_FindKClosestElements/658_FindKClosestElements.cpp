//O(n^2)
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
//O(logn)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-k;

        while(left < right){
            //mid is the leftmost element of sliding window
            //mid+k is the rightmost element 
            int mid = left + (right-left)/2;
            if(x - arr[mid] > arr[mid+k] - x)left = mid+1;
            else right = mid;
        }
        return vector<int> (arr.begin()+left,arr.begin()+left+k);
    }
};