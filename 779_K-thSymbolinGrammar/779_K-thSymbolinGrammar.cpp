//Kind of binary search
//O(height)
//O(1)
class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr = 0;
        int left = 1;
        int right = pow(2,n-1);   

        for(int i = 1;i < n;++i){ //do n-1 times because 1st row is 0
            // int mid = (left + right) / 2;
            int mid  = left + (right-left)/2;

            if(k <= mid){//in left part
                right = mid;
                //no need to update value because the left side of 0 is still 0 and 1 still be 1
            }else{
                left = mid + 1;
                //update the value
                curr = (curr == 0?1:0);
            }
        }
        return curr;
    }
};