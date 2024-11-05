//TC : O(n^2), if using traditional brute force , wuold be O(n^3)
//SC :O(1)
/*
    if the string size is odd then middle-out from the each char
    if the string size is even then middlde-out from each char and its next one
    O(n^2),O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxstart,maxlen = 0;

        for(int i = 0;i < s.size();++i){
            dp_MidleOutCheck(s,i,i,maxstart,maxlen); // odd length : babad
            dp_MidleOutCheck(s,i,i+1,maxstart,maxlen); // even : abbc
        }
        return s.substr(maxstart,maxlen);
    }
    void dp_MidleOutCheck(string& s,int left,int right,int& maxstart,int& maxlen){
        //check if palindromic
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        //update maxstart ,maxlen
        if(right - left - 1 > maxlen){
            maxstart = left + 1;
            maxlen = right - left - 1;//中間才算確認是回文
        }
    }
};