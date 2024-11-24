// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         unordered_map<int,int> mp;
//         priority_queue<pair<int,int>> pq;
        
//         for(auto num:nums)mp[num]++;
//         for(auto m : mp)pq.push({m.first, m.second});
        
//         while(k > pq.top().second){
//             k -= pq.top().second;
//             pq.pop();
//         }
//         return pq.top().first;
//     }
// };

//Best and avg TC :O(n), Worst : O(n^2)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int left = 0, right = nums.size() - 1;
//         while (true) {
//             int pos = partition(nums, left, right);
//             if (pos == k - 1) return nums[pos];
//             if (pos > k - 1) right = pos - 1;
//             else left = pos + 1;
//         }
//     }
//     int partition(vector<int>& nums, int left, int right) {//left part is greater than pivot
//         int pivot = nums[left], l = left + 1, r = right;
//         while (l <= r) {
//             if (nums[l] < pivot && nums[r] > pivot) {
//                 swap(nums[l++], nums[r--]);
//             }
//             if (nums[l] >= pivot) ++l;
//             if (nums[r] <= pivot) --r;
//         }
//         swap(nums[left], nums[r]);
//         return r;
//     }
// };


// worst TC O(n^2), avg O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int reverseK = nums.size()-k;
        return quickSelect(nums, 0, nums.size()-1, reverseK);
    }
    int quickSelect(vector<int>& nums, int left, int right, int reverseK){
        int pivot = nums[right];
        int position = left;
        
        for(int i = left; i < right;++i){ // no need to do the whole array
            if (nums[i] < pivot){
                swap(nums[i], nums[position]); //move the number less than pivot to left part
                position += 1;
            }
        }
        swap(nums[right], nums[position]);
        
        if (position > reverseK)return quickSelect(nums, left, position-1, reverseK);
        else if (position < reverseK)return quickSelect(nums, position+1, right,reverseK);
        else return nums[position];
    }
};