// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         if (s.back() != '0')
//             return false;
//         const int n = s.length();
//         queue<int> q{{0}};
//         for (int i = minJump; i < n; ++i) {
//             if (s[i] != '0')
//                 continue;
//             while (!q.empty() && q.front() + maxJump < i)
//                 q.pop();
//             if (!q.empty() && q.front() + minJump <= i)
//                 q.push(i);
//         }
//         return q.back() == n - 1;
//     }
// };

//both sol above and below are all O(n),O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() != '0')
            return false;
        const int n = s.length();
        queue<int> q{{0}};
        int farthest = 0;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            int start = max(i+minJump,farthest+1);
            int bound = min(i+maxJump+1,n);

            for(int j = start; j < bound;++j){
                if(s[j] == '0') {
                    q.push(j);
                    if(j == n-1)return true;
                }
            }
            farthest = i+maxJump;
        }
        return false;
    }
};