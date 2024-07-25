//O(1)
//O(1)
// First, put numbers 1-9 into the queue. Start by extracting from 1 and checking if it is between low and high.
// If it is, add it to the result vector (res).
// Then, according to the rules, extend the number by one digit (value is the previous digit 'd' plus one).
// 'd' must be less than 9, and then put the new number back into the queue.
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;
        for(int i = 1;i <= 9 ;++i)q.push(i);

        while(!q.empty()){
            int num = q.front();q.pop();

            if(num > high)continue;
            if(num >= low && num <= high)res.push_back(num);
            
            int d = num%10;
            if (d < 9) q.push(num * 10 + d + 1);
        }
        return res;
    }
};