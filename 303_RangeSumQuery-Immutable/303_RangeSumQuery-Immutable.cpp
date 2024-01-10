// class NumArray {
// public:
//   NumArray(vector<int> nums): sums_(nums) {      
//     if (nums.empty()) return;            
//     for (int i = 1; i < nums.size();++i)
//       sums_[i] += sums_[i - 1];
//   }
 
//   int sumRange(int i, int j) {
//     if (i == 0) return sums_[j];
//     return sums_[j] - sums_[i-1];
//   }
// private:    
//   vector<int> sums_;
// };

//1D DP
class NumArray {
public:
    NumArray(vector<int> &nums) {
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
    
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */