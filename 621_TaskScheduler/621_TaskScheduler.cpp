//O(NlogN),O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        priority_queue<int> freq;
        queue<pair<int,int>> taskqueue;
        int time = 0;
        
        for(char task:tasks){
            count[task-'A']++;
        }
        
        for(auto cnt:count){
            if(cnt > 0)freq.push(cnt);
        }
        
        while(!taskqueue.empty() || !freq.empty()){
            time++;
            
            if (!freq.empty()){
                int cnt = freq.top()-1;
                freq.pop();
                if (cnt > 0)taskqueue.push({cnt,time+n});
            }else {
                time = taskqueue.front().second;
            }
            
            if (!taskqueue.empty() && taskqueue.front().second == time) {
                freq.push(taskqueue.front().first);
                taskqueue.pop();
            }
        }
        return time;
    }
};
