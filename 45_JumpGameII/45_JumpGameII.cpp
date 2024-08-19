//O(n)
//O(1)
/*Greedy, sliding window, BFS concept
Find the farthest boundary each element in the interval can jump
brute force will cost O(n^n), dp will cost(n^2) */
class Solution {
public:
    int jump(vector<int>& nums) {
        int right = 0;
        int left = 0;
        int count = 0;
        
        while(right < nums.size()-1) {
            int farthest = 0;
            //update the window boundary
            for(int i = left;i < right+1;++i){
                farthest = max(farthest, nums[i]+i);
            }

            left = right + 1;
            right = farthest;
            count++;
        }
        return count;
    }
};