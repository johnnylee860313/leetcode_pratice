class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ME;
        unordered_map<int,int> count;

        for(auto num:nums){
            if(count.count(num)){
                count[num]++;
            }else{
                count[num] = 1;
            }
            if(count[num] > nums.size()/3 && !std::count(ME.begin(),ME.end(),num))ME.push_back(num);
        }

        return ME;
    }
};