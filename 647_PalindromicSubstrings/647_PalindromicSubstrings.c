//ref 5. LongestPalindromicSubstring
//TC : O(n^2)
//SC : O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0;i < s.size();++i){
            //odd length
            dp_MiddleOut(s,i,i,res);
            //even length
            dp_MiddleOut(s,i,i+1,res);
        }
        return res;
    }
    void dp_MiddleOut(string &s,int left,int right,int& res){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            res++;
        }
    }
};