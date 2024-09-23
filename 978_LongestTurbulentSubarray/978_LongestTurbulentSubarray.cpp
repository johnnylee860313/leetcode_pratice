//O(n)
//O(1)
/*sliding window concept*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res  = 1;
        int right = 1;
        int left = 0;
        string prev = "";

        while(right < arr.size()) {
            if (arr[right-1] > arr[right] && prev != ">") {
                res = max(res, right-left+1);
                right += 1;
                prev = ">";
            } else if (arr[right-1] < arr[right] && prev != "<") {
                res = max(res, right-left+1);
                right += 1;
                prev = "<";
            } else {
                right = (arr[right-1] == arr[right]?right+1:right);
                left = right-1;
                prev = "";
            }
        }
        return res;
    }
};