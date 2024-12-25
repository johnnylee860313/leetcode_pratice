class Solution {
public:
    int titleToNumber(string columnTitle) {
        int digit = columnTitle.size();
        int sum = 0;
        
        for(auto alph:columnTitle){
            sum += (alph-'A'+1) * pow(26, digit-1);
            digit--;
        }
        return sum;
    }
};
