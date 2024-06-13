//O(n)
//O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hash;
        int sum = 0;
        int res = 0;
        hash[0] = -1;

        for(int i = 0;i < nums.size();++i){
            sum += (nums[i] == 0?-1:1);
            
            //sum never occurs, meaning number of a and 0 are not equal
            if(hash.count(sum) == 0)hash[sum] = i;
            else{
                res = max(res,i-hash[sum]);
            }
        }
        return res;
    }
};

