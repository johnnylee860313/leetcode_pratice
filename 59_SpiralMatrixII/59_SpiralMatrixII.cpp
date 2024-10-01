//O(n^2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int up = 0;
        int bottom = n-1;
        vector<vector<int>>spmx(n, vector<int>(n));
        int val = 1;

        while(true) {
            for(int j = left; j <= right;++j)spmx[up][j] = val++;
            
            if (++up > bottom)break;
            for(int j = up; j <= bottom ;++j)spmx[j][right] = val++;
            
            if (--right < left)break;
            for(int j = right; j >= left; --j)spmx[bottom][j] = val++;

            if (--bottom < up)break;
            for(int j = bottom; j >= up; --j)spmx[j][left] = val++;

            if (++left > right) break;
        }
        return spmx;
    }
};