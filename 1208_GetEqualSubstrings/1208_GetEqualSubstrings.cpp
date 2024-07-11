// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         int currCost = 0;
//         int res = 0;
        
//         for(int left = 0,right = 0;right<s.size();++right){
//             currCost += abs(s[right] - t[right]);
//             while(currCost > maxCost){
//                 currCost -= abs(s[left] - t[left]);
//                 left++;
//             }
//             res = (res >= (right-left+1)?res:(right-left+1));
//         }
//         return res;
//     }
// };
//O(n),O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, n = s.size(), cur = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            cur += abs(s[i] - t[i]);
            while (cur > maxCost && start <= i) {
                cur -= abs(s[start] - t[start]);
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};
