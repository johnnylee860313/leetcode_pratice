class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    const int n = nums.size();
    unordered_set<int> seen(1 << n);
    for (const string& num : nums)
      seen.insert(bitset<16>(num).to_ulong());//to unsigned int
    // cout<<bitset<16>(2).to_string()<<endl;
    // cout<<bitset<16>(3).to_string().substr(16 - n)<<endl;

    for (int i = 0; i < 1 << n; ++i)
      if (!seen.count(i)) return bitset<16>(i).to_string().substr(16 - n);//to binary in string
    return "";
  }
};
// class Solution {//對角證法
// public:
//   string findDifferentBinaryString(vector<string>& nums) {    
//     const int n = nums.size();
//     string ans(n, '0');
//     for (int i = 0; i < n; ++i)
//       ans[i] = '1' - nums[i][i] + '0';
//     return ans;
//   }
// };