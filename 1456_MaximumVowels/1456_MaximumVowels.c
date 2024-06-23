class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int max = 0,tempt = 0;
        int left = 0,right = k-1;

        for(int i = left;i <= right;++i){
            if(isVowel(s[i]))max++;
        }
        tempt = max;
        while(right < s.size()){
            if(isVowel(s[left]) && tempt > 0){
                tempt--;
            }
            left++;
            right++;
            if(isVowel(s[right])){
                tempt++;
            }
            max = max > tempt?max:tempt;
        }
        return max;
    }
};