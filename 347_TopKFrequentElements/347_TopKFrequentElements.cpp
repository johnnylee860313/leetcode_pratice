//O(NlogN),O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> mh;
        vector<int> topK;
        
        for(auto n : nums)mp[n]++;
        for(auto m : mp) mh.push({m.second,m.first});
        
        while(k > 0){
            topK.push_back(mh.top().second);
            k--;
            mh.pop();
        }
        return topK;
        
    }
};

//O(N),O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int,int> mp;
        vector<int> topK;
        
        for(auto n : nums)mp[n]++;
        for(auto m : mp) bucket[m.second].push_back(m.first);
        
        int j = nums.size();
    
        for (int i = nums.size(); i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                topK.push_back(bucket[i][j]);
                if (topK.size() == k) return topK;
            }
        }
        return topK;
    }
};