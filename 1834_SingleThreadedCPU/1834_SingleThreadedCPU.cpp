//O(2n)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> valid;
        vector<int> ans;
        long int timestamp;

        for(int i = 0;i < tasks.size();++i){
            pq.push({tasks[i][0],tasks[i][1],i});
        }
        timestamp = pq.top()[0];
        
        while(!pq.empty() || !valid.empty()){
            while(!pq.empty() && timestamp >= pq.top()[0]){//in the time now, pick those processes which is available
                auto curr = pq.top();
                pq.pop();
                valid.push({curr[1],curr[2]});//push processing time and index into valid queue
            }
            if(valid.empty()){
                timestamp = pq.top()[0];
                continue;
            }

            auto validTop = valid.top();
            valid.pop();
            ans.push_back(validTop[1]);
            timestamp += validTop[0];
        }
        return ans;
    }
};