// class Solution {
// public:
//     string kthLargestNumber(vector<string>& nums, int k) {
//         //accending order
//         sort(nums.begin(),nums.end(),sorting);
//         return nums[nums.size()-k];//k-1
//     }
//     static bool sorting(string &a,string &b){
//         if(a.size() == b.size())return a < b;
//         return a.size() < b.size();
//     }
// };

// lamda function is faster
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        //accending order
        //if a and b are having same digit,then compare their ascii code 
        //if not then compare their number of digit is enough
        sort(nums.begin(),nums.end(),[](string& a,string& b){
            if(a.size() == b.size())return a < b;
            return a.size() < b.size();
        });
        return nums[nums.size()-k];//k-1
    }
};

