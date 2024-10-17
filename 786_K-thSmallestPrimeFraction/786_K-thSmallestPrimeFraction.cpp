//O(nlogn) binary search and two pointer
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = 0, right = 1;
        int p = 0, q = 1, cnt = 0, n = A.size();
        while (true) {
            double mid = left + (right - left) / 2.0;
            cnt = 0; p = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && A[i] > mid * A[j]) ++j;
                cnt += n - j;
                if (j < n && p * A[j] < q * A[i]) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (cnt == K) return {p, q};
            if (cnt < K) left = mid;
            else right = mid;
        }
    }
};