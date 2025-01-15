
// class Solution {
// public:
//     int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
//         int n = nums.size();
//         vector<int> presum(n + 1, 0);
        
//         // 計算前綴和
//         for (int i = 0; i < n; i++) {
//             presum[i + 1] = presum[i] + nums[i];
//         }
        
//         // 兩種排列可能的最大值
//         int max1 = getMax(presum, firstLen, secondLen);
//         int max2 = getMax(presum, secondLen, firstLen);
        
//         // 返回兩者的最大值
//         return max(max1, max2);
//     }

// private:
//     int getMax(const vector<int>& presum, int firstLen, int secondLen) {
//         int maxFirst = 0;  // firstLen 的最大值
//         int maxResult = 0; // 整體的最大值
        
//         for (int i = firstLen + secondLen; i < presum.size(); i++) {
//             // 計算第一個子陣列的最大值
//             maxFirst = max(maxFirst, presum[i - secondLen] - presum[i - secondLen - firstLen]);
            
//             // 計算整體的最大值
//             maxResult = max(maxResult, maxFirst + presum[i] - presum[i - secondLen]);
//         }
        
//         return maxResult;
//     }
// };

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // 將 nums 修改為前綴和 (prefix sum)
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        // 分別計算兩種排列方式的最大值
        int max1 = getMax(nums, firstLen, secondLen);
        int max2 = getMax(nums, secondLen, firstLen);
        return max(max1, max2);
    }

private:
    int getMax(const vector<int>& nums, int firstLen, int secondLen) {
        int maxFirst = 0;  // 第一個子陣列的最大值
        int maxResult = 0; // 總的最大值

        for (int i = firstLen + secondLen - 1; i < nums.size(); ++i) {
            // 計算第一個子陣列的和
            int firstSum = nums[i - secondLen] - (i - secondLen - firstLen >= 0 ? nums[i - secondLen - firstLen] : 0);
            maxFirst = max(maxFirst, firstSum);

            // 計算第二個子陣列的和
            int secondSum = nums[i] - nums[i - secondLen];

            // 更新總的最大值
            maxResult = max(maxResult, maxFirst + secondSum);
        }

        return maxResult;
    }
};
