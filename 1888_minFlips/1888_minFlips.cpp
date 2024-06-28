//sliding window
//double the string s and slide the window from left to right
//to check the difference between each digit of the string s and the alt string
//O(n)
//O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();//n is the original s size
        string alt0 = "";//begin with 0
        string alt1 = "";//begin with 1
        int diff0 = 0;
        int diff1 = 0;
        int left = 0;
        int flipcount = n;
        s = s + s;

        for(int i = 0;i < s.size();++i){//initialize the alt string
            if(i % 2 == 0){ //even digit
                alt0 += '0';
                alt1 += '1';
            }else{//odd digit
                alt0 += '1';
                alt1 += '0';
            }
        }

        for(int right = 0;right < s.size();++right){
            if(s[right] != alt0[right])diff0++;
            if(s[right] != alt1[right])diff1++;

            if(right - left + 1 > n){//slide the window when window size greater than n
                if(s[left] != alt0[left])diff0--;
                if(s[left] != alt1[left])diff1--;
                left++;
            }

            if(right - left + 1 == n){//update the ans when window size = n
                flipcount = flipcount > diff0?diff0:flipcount;
                flipcount = flipcount > diff1?diff1:flipcount;
            }
        }
        return flipcount;
    }
};