//O(logn),O(logn)

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sum;
        
        while(sum.find(n) == sum.end()){
            sum.insert(n);
            n = sumOfSquares(n);
            if (n == 1)return true;
            
        }
        return n==1;
    }
private :
    int sumOfSquares(int n){
        int output = 0;
        while(n != 0){
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};
