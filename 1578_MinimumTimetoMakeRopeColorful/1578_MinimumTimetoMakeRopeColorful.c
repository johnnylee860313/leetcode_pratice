//two pointer, greedy
//O(n)
//O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0;
        int res = 0;

        for(int right = 1;right < colors.size();++right){
            if(colors[left] == colors[right]){
                if(neededTime[left] <= neededTime[right]){
                    res += neededTime[left];
                    left = right;
                }else{
                    res += neededTime[right];
                }
            }else{
                left = right;
            }
        }
        return res;  
    }
};