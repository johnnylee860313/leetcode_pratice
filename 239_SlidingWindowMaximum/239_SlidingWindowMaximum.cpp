class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        deque<int> dq;
        vector<int> res(nums.size()-k+1);
        // 8,7,6,9, k=2
        // 1,1,1,1,0,7
        //put the number in the window with decreasing order into dequeue
        
        while(right < nums.size()){
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            
            if(left > dq.front()){
                dq.pop_front();
            }
            
            if((right + 1) >= k){
                res[left] = nums[dq.front()];
                left++;
            }
            right++;
        }
        return res;
    }
};