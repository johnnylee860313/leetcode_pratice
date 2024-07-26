//two pointer
//O(n)
//O(1)
class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size()-1;

        while(left < right && s[left] == s[right]){
            int tmpt = s[left];
            while(left <= right && s[left] == tmpt)left++;
            while(left <= right && s[right] == tmpt)right--;
        }
        return right-left+1;
    }
};