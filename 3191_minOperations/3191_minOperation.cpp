//O(3n)
//O(1)
/*
If nums[0] is 0, then the only way to change it to 1 is by doing an operation on the first 3 elements of the array.
After Changing nums[0] to 1, use the same logic on the remaining array.
Check if the final 2 elements in nums array are 1 to ensure whether it's possible
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation_count = 0;

        for(int i = 0;i < nums.size()-2;++i){
            if(nums[i] == 1)continue;
            for(int j = 0;j < 3;++j){
                nums[i+j] ^= 1;
            }
            operation_count++;
        }

        if(nums[nums.size()-1] == 0 || nums[nums.size()-2] == 0)return -1;
        return operation_count;
    }
};
// or
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