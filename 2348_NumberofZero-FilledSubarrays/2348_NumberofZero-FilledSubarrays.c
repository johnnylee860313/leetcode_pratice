class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int count = 0;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] == 0){
                count++;
                res += count;
            }else{
                count = 0;
            }
        }
        return res;
    }
};
// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long res = 0, count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i]) {
//                 res += (count * (count + 1)) / 2;
//                 count = 0;
//             } else 
//                 ++count;
//         }
//         res += (count * (count + 1)) / 2;
//         return res;
//     }
// };


//1,2,3,4,5,6
//1,3,6,10,15,21
/* n = number of zero
    ans = n*(n+1) */
/* or
0 -> 1
0,0 -> 1+2
0,0,0 -> 3+3
0,0,0,0 -> 6+4 */

