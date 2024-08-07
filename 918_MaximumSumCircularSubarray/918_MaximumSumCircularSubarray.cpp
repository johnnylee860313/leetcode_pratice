class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, globalmin = INT_MAX, globalmax = INT_MIN, curMax = 0, curMin = 0;
		for (int num : A) {
			curMin = (curMin + num) < num?(curMin + num):num;
            globalmin = globalmin < curMin?globalmin:curMin;
            curMax = (curMax + num) > num?(curMax + num):num;
            globalmax = globalmax > curMax?globalmax:curMax;
            total += num;
		}
        return (total - globalmin == 0) ? globalmax : max(globalmax, total - globalmin);
    }
};
//最大的subarray會是總額減掉最小的
//(total - globalmin == 0) 代表全是負數的狀況
